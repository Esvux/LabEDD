#include "jsonreader.h"
#include "time.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>

void JsonReader::fillListFromFile(DoubleList *list, QByteArray json) {
    QJsonDocument doc = QJsonDocument::fromJson(json);
    if(! doc.isArray()){
        QMessageBox::warning(nullptr, "JSON Clientes", "Error en el archivo, el elemento raíz debe ser un arreglo");
        return;
    }
    QJsonArray array = doc.array();
    int max = array.size();

    clock_t t;
    t = clock();
    for(int i = 0; i < max; i++) {
        QJsonValueRef ref = array[i];
        if(! ref.isObject())
            continue;
        QJsonObject obj = ref.toObject();
        QJsonValue nameValue = obj["nombre"];
        if(nameValue.isUndefined() || nameValue.isNull())
            continue;
        QJsonValue taxIdValue = obj["NIT"];
        if(taxIdValue.isUndefined() || taxIdValue.isNull())
            continue;
        list->insert(new DoubleNode(nameValue.toString(), taxIdValue.toString()));
    }
    t = clock() - t;
    //QString resume = QString::asprintf("Se cargaron correctamente %d de %d registros en %ld ciclos de reloj.", list->size(), max, t);
    QString resume = QString::asprintf("Se cargaron correctamente %d de %d registros en %f milisegundos.", list->size(), max, ((double)t / CLOCKS_PER_SEC) * 1000);
    QMessageBox::information(NULL, "Rendimiento lista doble", resume);
}
