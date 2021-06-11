#include "SimulationThread.h"

SimulationThread::SimulationThread(QObject *parent, bool b):QThread(parent), Stop(b)
{

}

void SimulationThread::run(){
    while(true){
        QMutex mutex;
        mutex.lock();
        if(this->Stop) break;
        mutex.unlock();

        emit nextStepCalculated();

        this->msleep(500);
    }
}
