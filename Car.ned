

package mincostvanet;

import org.mixim.base.modules.*;
import org.mixim.modules.nic.Nic80211p;

module Car
{
    parameters:
        string applType; //type of the application layer
        string mobilityType; //type of the mobility module
    gates:
        input radioIn; // gate for sendDirect
    submodules:
        appl: <applType> like IBaseApplLayer {
            parameters:
                @display("p=60,50");
        }

        arp: BaseArp {
            parameters:
                @display("p=130,108");
        }

        nic: Nic80211p {
            parameters:
                @display("p=60,166");
        }

        mobility: <mobilityType> like IMobility {
            parameters:
                @display("p=130,172;i=block/cogwheel");
        }
    connections:
        nic.upperLayerOut --> appl.lowerLayerIn;
        nic.upperLayerIn <-- appl.lowerLayerOut;
        nic.upperControlOut --> appl.lowerControlIn;
        nic.upperControlIn <-- appl.lowerControlOut;

        radioIn --> nic.radioIn;

}