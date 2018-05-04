package org.esvux.urbanedd.rest;

import java.util.Date;
import javax.ws.rs.Produces;
import javax.ws.rs.Consumes;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
import org.esvux.urbanedd.model.SolicitudTicket;
import org.esvux.urbanedd.model.Ticket;

/**
 * REST Web Service
 *
 * @author esvux
 */
@Path("tickets")
@Consumes(MediaType.APPLICATION_JSON)
@Produces(MediaType.APPLICATION_JSON)
public class TicketsResource {


    /**
     * Retrieves representation of an instance of org.esvux.urbanedd.rest.RutasResource
     * @return an empty response
     */
    @GET
    public Response getJson() {
        return Response.ok().build();
    }

    /**
     * PUT method for updating or creating an instance of RutasResource
     * @param content representation for the resource
     * @return new ticket
     */
    @POST
    public Response crearTicket(SolicitudTicket content) {
        Ticket ticket = new Ticket(
                (long)(Math.random() * 5000L), 
                "VERIF-0233652", 
                content.getMonto(), 
                new Date()
        );
        return Response.ok(ticket).build();
    }
}
