import java.util.*;
import java.util.Scanner;


class MinHeap{
    private int HeapArr[];
    private int size;
    private int lastIndex = 0;

    
    public MinHeap(int size){ 
        this.size = size;
        HeapArr = new int[size];
    } 
    public void last(){
        System.out.println(lastIndex);
        System.out.println(HeapArr[lastIndex]);
    }
    public void insert(int val){
        HeapArr[lastIndex]=val;
        heapify(lastIndex);
        lastIndex++;        
    }

    public void decKey(int key,int amount){
        int ind = 0;
        while(HeapArr[ind]!=key){
            ind++;
        }
        HeapArr[ind]-=amount;
        heapify(ind);
    }

    public int getParentIndex(int ind){
        return (ind-1)/2;
    }

    public int getLeftChild(int ind){
        return (2*ind)+1;
    }
    
    public int getRightChild(int ind){
        return (2*ind)+2;
    }

    public int getMax(){
        return HeapArr[0];
    }

    public int extractMax(){
        int temp = HeapArr[0];
        lastIndex--;
        HeapArr[0] = HeapArr[lastIndex];
        HeapArr[lastIndex]=0;
        heapify(0);
        return temp;
    }
    public void swap(int a, int b){
        int temp = HeapArr[a];
        HeapArr[a]=HeapArr[b];
        HeapArr[b]=temp;
    }

    public void heapify(int ind){
        int leftChild = HeapArr[getLeftChild(ind)];
        int rightChild = HeapArr[getRightChild(ind)];
        int parent = HeapArr[ind];
        int casex;
        
        if((rightChild<leftChild) && leftChild!=0){
            casex = 1;
        }
        else if ((leftChild<rightChild) && rightChild!=0){
            casex = 2;
        }
        else{
            casex = 3;
        }

        switch(casex){
            case 1:
                if (leftChild < parent){
                    swap(getLeftChild(ind),getParentIndex(ind));
                    heapify(getLeftChild(ind));
                    parent = HeapArr[ind];
                }
                break;
            case 2:
                if(rightChild<parent){
                    swap(getRightChild(ind),getParentIndex(ind));
                    heapify(getRightChild(ind));
                    parent = HeapArr[ind];
                }
                break;
            case 3:
                break;
        }

        parent = getParentIndex(ind);
        if (parent>=0){
            if(HeapArr[ind]>HeapArr[parent]){
                swap(ind,parent);
                heapify(parent);
            }
        }
        return;
        
    }


    public static void main(String[] args){
        MinHeap maxHeap = new MinHeap(1000);
        maxHeap.insert(5);
        maxHeap.insert(15);
        maxHeap.insert(10);
        maxHeap.insert(17);
        maxHeap.insert(20);
        maxHeap.insert(12);
        maxHeap.insert(8);
        //maxHeap.extractMax();
        maxHeap.insert(22);
        //maxHeap.last();
        maxHeap.decKey(17,10);
        //System.out.println(maxHeap.extractMax());
        for (int i=0;i<16;i++){
            if (maxHeap.HeapArr[i]!=0){
                System.out.println(maxHeap.HeapArr[i]);
            }
        }
    }
}