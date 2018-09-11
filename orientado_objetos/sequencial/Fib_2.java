/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sequencial;

/**
 *
 * @author Jardel Carvalho
 */
public class Fib_2 {
    
    private long soma(long a, long b) {
        return a + b;
    }
    
    public long fib(int n) {
        long anterior, atual, guardaAtual;
        
        anterior = 0;
        atual = 1;
        
        for(; n != 1; n--) {
            guardaAtual = atual;
            atual = soma(atual, anterior);
            anterior = guardaAtual;
        }
        
        return atual; 
    }
}
