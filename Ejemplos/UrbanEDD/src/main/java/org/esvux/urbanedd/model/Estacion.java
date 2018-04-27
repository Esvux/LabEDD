package org.esvux.urbanedd.model;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.ObjectWriter;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.validation.constraints.NotNull;

/**
 *
 * @author esvux
 */
public class Estacion {
    
    private String nombre;    
    private String color;
    
    
    public Estacion() {
    }
        
    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }
    
    @Override
    public String toString() {
        ObjectWriter ow = new ObjectMapper().writer().withDefaultPrettyPrinter();
        try {
            return ow.writeValueAsString(this);
        } catch (JsonProcessingException ex) {
            Logger.getLogger(Estacion.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;
    }   
    
}
