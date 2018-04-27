package org.esvux.urbanedd.model;

import java.io.Serializable;

/**
 *
 * @author esvux
 */
public class Curso implements Serializable {

    private String nombre;
    private int nota;

    public Curso() {
    }

    public Curso(String nombre, int nota) {
        this.nombre = nombre;
        this.nota = nota;
    }

    public int getNota() {
        return nota;
    }

    public void setNota(int nota) {
        this.nota = nota;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
    
}
