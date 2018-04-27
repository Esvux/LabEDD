package org.esvux.urbanedd.rest;

import javax.ws.rs.Produces;
import javax.ws.rs.Consumes;
import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.PUT;
import javax.ws.rs.core.MediaType;
import org.esvux.urbanedd.model.Ruta;

/**
 * REST Web Service
 *
 * @author esvux
 */
@Path("rutas")
public class RutasResource {


    /**
     * Retrieves representation of an instance of org.esvux.urbanedd.rest.RutasResource
     * @return an instance of org.esvux.urbanedd.model.Ruta
     */
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public Ruta getJson() {
        //TODO return proper representation object
        return new Ruta("Ruta Universisdad", "#446677", "203");
    }

    /**
     * PUT method for updating or creating an instance of RutasResource
     * @param content representation for the resource
     */
    @PUT
    @Consumes(MediaType.APPLICATION_JSON)
    public void putJson(Ruta content) {
    }
}
