package org.esvux.urbanedd.model;

import com.fasterxml.jackson.annotation.JsonFormat;
import java.util.Date;

/**
 *
 * @author esvux
 */
public class Ticket {
    private long numero;
    private String verificacion;
    private double saldo;
    
    @JsonFormat(pattern = "yyyy-MM-dd")
    private Date fecha;

    public Ticket(long numero, String verificacion, double saldo, Date fecha) {
        this.numero = numero;
        this.verificacion = verificacion;
        this.saldo = saldo;
        this.fecha = fecha;
    }

    public Ticket() {
    }

    public long getNumero() {
        return numero;
    }

    public void setNumero(long numero) {
        this.numero = numero;
    }

    public String getVerificacion() {
        return verificacion;
    }

    public void setVerificacion(String verificacion) {
        this.verificacion = verificacion;
    }

    public double getSaldo() {
        return saldo;
    }

    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    public Date getFecha() {
        return fecha;
    }

    public void setFecha(Date fecha) {
        this.fecha = fecha;
    }
    
}
