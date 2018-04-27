/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package org.esvux.urbanedd.model;

/**
 *
 * @author esvux
 */
public class Ruta {
    
    private String nombre;
    private String color;
    private String codigo;

    public Ruta(String nombre, String color, String codigo) {
        this.nombre = nombre;
        this.color = color;
        this.codigo = codigo;
    }

    public Ruta() {
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

    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }
       
}
