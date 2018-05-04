package org.esvux.urbanedd.model;


/**
 *
 * @author esvux
 */
public class ListaGenerica<T> {

    private static ListaGenerica<Estacion> singletonEstaciones = null;
    
    public synchronized static ListaGenerica<Estacion> getListaEstaciones() {
        if(singletonEstaciones==null)
            singletonEstaciones = new ListaGenerica<>();
        return singletonEstaciones;
    }
    
    private static ListaGenerica<Ruta> singletonRutas = null;
    
    public static ListaGenerica<Ruta> getListaRutas() {
        if(singletonRutas==null)
            singletonRutas = new ListaGenerica<>();
        return singletonRutas;
    }
    
    private NodoEstacion<T> primero;
    
    public ListaGenerica() {
    }
    
    public void add(T estacion){
        if(primero==null) {
            primero = new NodoEstacion(estacion);
            return;
        }
        NodoEstacion nuevo = new NodoEstacion(estacion);
        nuevo.siguiente = primero;
        primero = nuevo;
    }
    
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("[");
        NodoEstacion temporal = primero;
        while(temporal!=null) {
            sb.append(temporal.contenido);
            temporal = temporal.siguiente;
            if(temporal!=null) {
                sb.append(",");
            }
        }
        sb.append("]");
        return sb.toString();
    }
    
    private class NodoEstacion<T> {
        T contenido;
        NodoEstacion<T> siguiente;
        NodoEstacion(T estacion) {
            this.contenido = estacion;
        }
        @Override
        public String toString() {
            return contenido.toString();
        }
    }
    
}
