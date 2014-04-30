//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef RSUAPPLLAYER_H_
#define RSUAPPLLAYER_H_

#include <omnetpp.h>
#include <BaseWaveApplLayer.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

#ifndef DBG
#define DBG EV
#endif

class RSUApplLayer: public BaseWaveApplLayer {
public:
    RSUApplLayer();
    virtual ~RSUApplLayer();
    virtual void initialize(int stage);

public:
    virtual void onBeacon(WaveShortMessage* wsm);
    virtual void onData(WaveShortMessage* wsm);

protected:
    uint32_t receivedBeacons;
    uint32_t receivedData;
};

#endif /* RSUAPPLLAYER_H_ */

