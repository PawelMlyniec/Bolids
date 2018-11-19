

#ifndef MONITORS_BOILDSMONITOR_H
#define MONITORS_BOILDSMONITOR_H


#include "monitor.h"

int N; //bolid number
int K; //spaces in alley
int P; //max priority
int L; //refiling number

class bolidMonitor: Monitor {
    Condition exitLine, entryLine;
    int inAlley, exit, entry;
    bool freeServiceLine;
public:
    bolidMonitor() {
        inAlley = 0;
        exit = 0;
        entry = 0;
        freeServiceLine = true;

    }

    void getIn() {
        enter();
        if (freeServiceLine && inAlley < K) {
            freeServiceLine = false;
            leave();

        } else {
            wait(entryLine);
            freeServiceLine = false;
            leave();
        }


    }

    void takeAlley() {
        enter();
        inAlley++;
        freeServiceLine = true;
        if (inAlley < P) {
            if (signal(entryLine))
                0 == 0;
            else if (signal(exitLine))
                0 == 0;


        } else {
            if (signal(exitLine))
                0 == 0;
            else if (signal(entryLine))
                0 == 0;


        }
        leave();


    }

    void leaveAlley() {
        enter();
        if (!freeServiceLine)
            wait(exitLine);
        freeServiceLine = false;
        leave();


    }

    void getOut() {
        enter();
        if (inAlley < P) {
            if (signal(entryLine))
                0 == 0;
            else if (signal(exitLine))
                0 == 0;
            leave();

        } else {
            if (signal(exitLine))
                0 == 0;
            else if (signal(entryLine))
                0 == 0;

            inAlley--;
            freeServiceLine = true;
            leave();

        }
    }
};

#endif //MONITORS_BOILDSMONITOR_H
