package org.esvux.urbanedd.model;

import javax.enterprise.context.ApplicationScoped;

/**
 *
 * @author esvux
 */
@ApplicationScoped
public class ListaEstaciones {

    private NodoEstacion primero;
    
    public ListaEstaciones() {
    }
    
    public void add(Estacion estacion){
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
            sb.append(temporal.estacion);
            temporal = temporal.siguiente;
            if(temporal!=null) {
                sb.append(",");
            }
        }
        sb.append("]");
        return sb.toString();
    }
    
    private class NodoEstacion {
        Estacion estacion;
        NodoEstacion siguiente;
        NodoEstacion(Estacion estacion) {
            this.estacion = estacion;
        }
        @Override
        public String toString() {
            return estacion.toString();
        }
    }
    
}
