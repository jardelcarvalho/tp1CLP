/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package recursivo;

/**
 *
 * @author Jardel Carvalho
 */
public class Fib_Recursivo_Cauda {
    
    public long fib(int n) { 
        return calcfib(n, 0, 1);
    }
    
     private long calcfib(int n, long anterior, long atual) {
        if(n == 1) {
            return atual;
        }
        return calcfib(n - 1, atual, anterior + atual);
    }
}
