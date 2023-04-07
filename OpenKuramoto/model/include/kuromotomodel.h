#ifndef KUROMOTOMODEL_H
#define KUROMOTOMODEL_H

#include "synchronizationmodel.h"
#include "eulerscheme.h"

#include "stdlib.h"

class KuromotoModel
        : public SynchronizationModel
{
    double delta_;
    Oscillator* oscillator_;
    FiniteDifferenceMethod* scheme_;
public:
    KuromotoModel(OscillatorSystem* _system, FiniteDifferenceMethod* _scheme);
    ~KuromotoModel();
    void compute();
    double getSelfConsistentFunction(MaterialPoint* _object);
};

#endif // KUROMOTOMODEL_H
