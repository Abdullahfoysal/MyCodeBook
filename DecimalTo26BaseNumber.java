/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.swe.mycompetative;


import java.io.File;
import java.io.FileNotFoundException;
import static java.lang.Integer.min;
import static java.lang.Math.abs;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Stack;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author foysalmac
 */

public class A {
   
    /**
     * @param args the command line arguments
     */
     public static void main(String args[]) throws FileNotFoundException {
        
         
        Scanner scan = new Scanner(new File("src/main/java/com/swe/mycompetative/input.txt"));
        
       int n;
       n= scan.nextInt();
       String alphabet="ZABCDEFGHIJKLMNOPQRSTUVWXY";
       Stack<Integer> stack =new Stack<Integer>();
       int dividend=n;
        while(dividend!=0){
            int r = dividend%26;
            stack.push(r);
            dividend/=26;
        }
        
       while(!stack.empty()){
          int index =stack.pop();
           System.out.print(alphabet.charAt(index));
       }
   
       
    }
     

 
    
    
   
}


