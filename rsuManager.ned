
package mincostvanet;
//
// VACaMobil was presented in:
// 
// [1] M. Báguena, S. M. Tornell, A. Torres, C. T. Calafate, J.-C. Cano, and P. Manzoni, 
// “VACaMobil: VANET Car Mobility Manager for OMNeT++,” in IEEE International Conference
// on Communications 2013: IEEE ICC’13 - 3rd IEEE International Workshop on Smart 
// Communication Protocols and Algorithms (SCPA 2013) (ICC'13 - IEEE ICC'13 - Workshop SCPA), 2013.
//
// please cite our paper if you use it.
// 
// If you use VACaMobil for your publications, please inform us at www.grc.upv.es
//

simple RSUManager{
  	  parameters: 
  	@display("i=block/source"); 
  	@class("RSUMananger"); 
  	xml rsuPlacement = default(xml("<poas></poas>")); 
  	string rsuModule = default(""); //the omnetpp module of RSU
  	string rsuPrefix = default(""); //the omnetpp module of RSU
  	int nRandomRsu = default(0); //number of RSU place randomly
    
}



