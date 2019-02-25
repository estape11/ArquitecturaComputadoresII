#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>

std::mutex mutex;
std::condition_variable condVar;
int size=500;
char arreglo [500]; // variable a compartir
char xorValor = 32; // 0x20

int getRandom255(){
  return std::rand() % 256;
}

void funcionHilo2(){
   int i = 0;
  while (i!=(size-1)){
    std::unique_lock<std::mutex> lck(mutex);
    condVar.wait(lck); // espera que hilo1 libere arreglo para acceder a el
    std::cout<<"> Char actual: "<<+arreglo[i]<<", con XOR: "<<+(arreglo[i]^xorValor)<<std::endl;
    i++;
  }
}

void funcionHilo1(){
  for (int i=0;i<size;i++){
    arreglo[i]=getRandom255();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    condVar.notify_one(); // notifica a los otros hilos que estan esperando para usar arreglo
  }
}

int main(){
  std::thread hilo1(funcionHilo1);
  std::thread hilo2(funcionHilo2);

  hilo1.join();
  hilo2.join();

  return true;
  
}