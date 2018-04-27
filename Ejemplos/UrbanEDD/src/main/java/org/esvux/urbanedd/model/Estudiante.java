package org.esvux.urbanedd.model;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author esvux
 */
public class Estudiante {
    
    private String nombre;
    private int carnet;
    private int porcentajeSuenio;
    private List<Curso> cursos;

    public Estudiante(String nombre, int carnet, int porcentajeSuenio) {
        this.nombre = nombre;
        this.carnet = carnet;
        this.porcentajeSuenio = porcentajeSuenio;
        this.cursos = new ArrayList<>();
    }

    public Estudiante() {
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public int getCarnet() {
        return carnet;
    }

    public void setCarnet(int carnet) {
        this.carnet = carnet;
    }

    public int getPorcentajeSuenio() {
        return porcentajeSuenio;
    }

    public void setPorcentajeSuenio(int porcentajeSuenio) {
        this.porcentajeSuenio = porcentajeSuenio;
    }    

    public List<Curso> getCursos() {
        return cursos;
    }

    public void setCursos(List<Curso> cursos) {
        this.cursos = cursos;
    }
    
    public Estudiante addCurso(Curso curso) {
        this.cursos.add(curso);
        return this;
    }
    
}
