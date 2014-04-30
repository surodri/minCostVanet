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

#include <RSUApplLayer.h>
#include <omnetpp.h>

RSUApplLayer::RSUApplLayer() {
    // TODO Auto-generated constructor stub

}

RSUApplLayer::~RSUApplLayer() {
    // TODO Auto-generated destructor stub
}



Define_Module(RSUApplLayer);
void RSUApplLayer:: initialize(int stage){
    BaseWaveApplLayer::initialize(stage);
    receivedBeacons = 0;
    receivedData = 0;
}

void RSUApplLayer::onBeacon(WaveShortMessage* wsm){
    receivedBeacons++;

    DBG << "Received beacon priority  " << wsm->getPriority() << " at " <<simTime() << std::endl;
    int senderId = wsm ->getSenderAddress();

    if(sendData){
        t_channel channel = dataOnSch ? type_SCH : type_CCH;
        sendWSM(prepareWSM("data", dataLengthBits, channel, dataPriority, senderId, 2));
    }
}

void RSUApplLayer::onData(WaveShortMessage* wsm){
    int recipientId = wsm->getRecipientAddress();

    if(recipientId == myId){
        DBG << "Received data priority " << " at " << simTime() << std::endl;
        receivedData++;
    }
}
