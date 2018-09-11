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
public class Fib_Recursivo {
    
    public long fib(int n) { 
       if(n == 0 || n == 1) {
           return n;
       }
       return fib(n - 1) + fib(n - 2);
    }
}
