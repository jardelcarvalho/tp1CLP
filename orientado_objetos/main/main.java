/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package main;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import sequencial.*;
import recursivo.*;
/**
 *
 * @author Jardel Carvalho
 */
public class main {
     /**
     * @param args the command line arguments
     */
    
    private static final int MILISEGUNDOS = 1;
    private static final int[] CASOS_TESTE = {10, 20, 30, 40, 50};
    
    public static void main(String[] args) {
        // TODO code application logic here
        /*int n = 10;
        
        System.out.println(new Fib_1().fib(n));
        System.out.println(new Fib_2().fib(n));
        System.out.println(new Fib_3().fib(n));
        System.out.println(new Fib_Recursivo().fib(n));
        System.out.println(new Fib_Recursivo_Cauda().fib(n));*/
        
        long t_inicio, t_fim, t_execucao;
        long total_1, total_2, total_3, total_r, total_r_c;
        total_1 = total_2 = total_3 = total_r = total_r_c = 0;
        
        FileOutputStream fout, medias;
        
        Fib_1 fib_1 = new Fib_1();
        Fib_2 fib_2 = new Fib_2();
        Fib_3 fib_3 = new Fib_3();
        Fib_Recursivo fib_r = new Fib_Recursivo();
        Fib_Recursivo_Cauda fib_r_c = new Fib_Recursivo_Cauda();
        
        try {
            
            fout = new FileOutputStream(new File("resultados/java.csv"));
            medias = new FileOutputStream(new File("resultados/medias_java_temp.csv"));
            
        } catch(FileNotFoundException e) {
            
            return;
            
        }
        
        try {
            
            fout.write(("Tipo.Tempo(nanosec).N\n").getBytes());
            
            for(int n : CASOS_TESTE) {
                
                t_inicio = System.nanoTime();
                fib_1.fib(n);
                t_fim = System.nanoTime();
                t_execucao = (t_fim - t_inicio) / MILISEGUNDOS;
                total_1 += t_execucao;
                fout.write(("Fib_1." + Long.toString(t_execucao) + "." + Integer.toString(n) + "\n").getBytes());
                

                t_inicio = System.nanoTime();
                fib_2.fib(n);
                t_fim = System.nanoTime();
                t_execucao = (t_fim - t_inicio) / MILISEGUNDOS;
                total_2 += t_execucao;
                fout.write(("Fib_2." + Long.toString(t_execucao) + "." + Integer.toString(n) + "\n").getBytes());


                t_inicio = System.nanoTime();
                fib_3.fib(n);
                t_fim = System.nanoTime();
                t_execucao = (t_fim - t_inicio) / MILISEGUNDOS;
                total_3 += t_execucao;
                fout.write(("Fib_3." + Long.toString(t_execucao) + "." + Integer.toString(n) + "\n").getBytes());


                t_inicio = System.nanoTime();
                fib_r.fib(n);
                t_fim = System.nanoTime();
                t_execucao = (t_fim - t_inicio) / MILISEGUNDOS;
                total_r += t_execucao;
                fout.write(("Fib_R." + Long.toString(t_execucao) + "." + Integer.toString(n) + "\n").getBytes());

                t_inicio = System.nanoTime();
                fib_r_c.fib(n);
                t_fim = System.nanoTime();
                t_execucao = (t_fim - t_inicio) / MILISEGUNDOS;
                total_r_c += t_execucao;
                fout.write(("Fib_R_C." + Long.toString(t_execucao) + "." + Integer.toString(n) + "\n").getBytes());
                
            }
            medias.write(((Long.toString(total_1 / CASOS_TESTE.length) + "\n")).getBytes());
            medias.write(((Long.toString(total_2 / CASOS_TESTE.length) + "\n")).getBytes());
            medias.write(((Long.toString(total_3 / CASOS_TESTE.length) + "\n")).getBytes());
            medias.write(((Long.toString(total_r / CASOS_TESTE.length) + "\n")).getBytes());
            medias.write(((Long.toString(total_r_c / CASOS_TESTE.length) + "\n")).getBytes());
            
            try {
             
                fout.close();
                medias.close();

            } catch(IOException f) {
                return;
            }
            
        } catch(IOException e) {
            
            return;
            
        }
    }
}
