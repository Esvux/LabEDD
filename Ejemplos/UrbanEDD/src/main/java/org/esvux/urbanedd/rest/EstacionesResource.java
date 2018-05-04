package org.esvux.urbanedd.rest;

import javax.ws.rs.Produces;
import javax.ws.rs.Consumes;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
import org.esvux.urbanedd.model.Estacion;
import org.esvux.urbanedd.model.ListaGenerica;

/**
 * REST Web Service
 *
 * @author esvux
 */
@Path("estaciones")
@Produces(MediaType.APPLICATION_JSON)
@Consumes(MediaType.APPLICATION_JSON)
public class EstacionesResource {

    private ListaGenerica<Estacion> estaciones = ListaGenerica.getListaEstaciones();
    
    /**
     * Retrieves representation of an instance of org.esvux.urbanedd.rest.EstacionesResource
     * @return an instance of org.esvux.urbanedd.model.Estacion
     */
    @GET
    public Response getEstaciones() {
        return Response.ok(estaciones.toString()).build();
        /*List<Estudiante> estudiantes = Arrays.asList(
                new Estudiante("Pablo", 201603191, 91)
                        .addCurso(new Curso("MB1", 61))
                        .addCurso(new Curso("Deportes2", 40)), 
                new Estudiante("Jose", 201602959, 80)
                        .addCurso(new Curso("IPC1", 61)),
                new Estudiante("Luis", 201612226, 70)
                        .addCurso(new Curso("EDD", 61))
                        .addCurso(new Curso("MA4", 61))
        );
        return Response.ok(estudiantes).build();
        */
    }
    
    /**
     * POST method for creating an instance of EstacionesResource
     * @param nueva representation for the resource
     * @return empty response
     */
    @POST
    public Response addEstacion(Estacion nueva) {
        estaciones.add(nueva);
        return Response.ok("{\"mensaje\":\"Ok\"}").build();
    }
    
}