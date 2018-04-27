# Ejemplo API REST
Este ejemplo fue desarrollado usando NetBeans 8.1

## Crear el nuevo proyecto
Se selecciona el menú `File`>`New Project...`, esto abre un wizard en el cual se selecciona la categoría `Maven` y luego `Web Application`, click en `Next`, luego escriben el nombre de la aplicación y el paquete principal de la misma. Se selecciona el servidor sobre el que se desplegará la aplicación, por último click en `Finish`.

![Nuevo proyecto](https://github.com/Esvux/LabEDD/blob/resources/Resources/000-project.png)

## Crear un nuevo endpoint
Antes de iniciar, se crean al menos dos paquetes, uno para los modelos (datos y estructuras) y otro para los endpoints. Para crear un nuevo endpoint se da click derecho sobre el paquete destinado para los endpoints y se selecciona la opción `New`>`RESTful Web Services from Patterns...`, el IDE desplegará un wizard en el cuál se selecciona la opción `Simple Root Resource` y click en `Next`; a continuación se ingresa el `Path`, el `MIME Type` (application/json para este ejemplo) y si ya se tienen creados los objetos se puede indicar `Representation Class`, de lo contrario se puede dejar la opción por defecto.

![Nuevo endpoint](https://github.com/Esvux/LabEDD/blob/resources/Resources/000-endpoint.png)

Al crear el primer endpoint se crearán dos clases en el paquete seleccionado, `ApplicationConfig` es la clase que agrupa y configura todos los endpoints que se crearán en la aplicación, además de determinar la base de la URL del API por medio de la anotación `@ApplicationPath`.

![Estructura del proyecto](https://github.com/Esvux/LabEDD/blob/resources/Resources/000-files.png)