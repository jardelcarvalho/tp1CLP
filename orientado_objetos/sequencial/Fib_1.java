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
public class Fib_1 {

    private long anterior, atual, guardaAtual;
    
    public long fib(int n) {
        anterior = 0;
        atual = 1;
        
        for(; n != 1; n--) {
            guardaAtual = atual;
            atual = atual + anterior;
            anterior = guardaAtual;
        }
        
        return atual; 
    }

}
