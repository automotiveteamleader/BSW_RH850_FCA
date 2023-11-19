#%VASE-API=1.0%
#######################################################################################################################
#  COPYRIGHT
#   -------------------------------------------------------------------------------------------------------------------
#   \verbatim
#   Copyright (c) 2016 by Vector Informatik GmbH.                                                  All rights reserved.
#
#                 This software is copyright protected and proprietary to Vector Informatik GmbH.
#                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
#                 All other rights remain with Vector Informatik GmbH.
#   \endverbatim
#   -------------------------------------------------------------------------------------------------------------------
#   FILE DESCRIPTION
#   -----------------------------------------------------------------------------------------------------------------*/
#        \brief  VASE script to delete Pdus from an ARXML File for the Bootloader
#######################################################################################################################
#
#######################################################################################################################
#  AUTHOR IDENTITY
#  -------------------------------------------------------------------------------------------------------------------
#  Name                          Initials      Company
#  -------------------------------------------------------------------------------------------------------------------
#  Andoni Rendon Borobia         visrai        Vector Informatik GmbH
#  -------------------------------------------------------------------------------------------------------------------
#  REVISION HISTORY
#  -------------------------------------------------------------------------------------------------------------------
#  Version   Date        Author  Change Id     Description
#  -------------------------------------------------------------------------------------------------------------------
#   1.00.00  2016-01-14  visrai  -             initial version
#   1.01.00  2016-03-01  visrai  -             minor fixes
#   1.02.00  2016-03-01  visrai  -             minor fixes
#   1.03.00  2016-10-23  visrai  -             Code redesigned, extended Version Ethernet and IPduMappings are included. Autosar 4.2.2
#   1.04.00  2017-07-03  visrai  -             XCPPdus and NMPdus can also be deleted

#######################################################################################################################




import clr
import os
import sys 
import System
import xml.etree.ElementTree as ET

clr.AddReference("System.Core") 
clr.AddReference("System.Linq")
clr.AddReference("System.Xml")
clr.AddReference("System.Xml.Linq")
from System.Xml.Linq import *
from System.Xml import *
from System.Linq import *

sys.path.append("C:\Program Files (x86)\IronPython 2.7\Lib")
clr.AddReference("GenTool_CsDataServerDomAsr4.dll")

#Simbole von den interfaces
from GenTool_CsDataServerDomAsr4.Iface import ITpConnection, ITpConfig, IFrame, IPhysicalChannel, ReferrableType, StorageConditionStatusEnum, EventAcceptanceStatusEnum, ByteOrderEnum, CommunicationDirectionType, ICommunicationConnector, IISignalIPdu, IISignalIPduGroup, IISignalIPduGroupBase , IFlexrayPhysicalChannel, IARPackage, IAUTOSAR

#Simbole von der Modellimplementierung
from GenTool_CsDataServerDomAsr4.Model import  *

clr.AddReference("System.Windows.Forms")
from System.Windows.Forms import *      
 
def Find(qualifiedPathName):
    return model.Find(qualifiedPathName)

def Log(message):
    logger.Log(3,message)      


#----------------------------------------------------------------------------------------------------------------
#-----------------------------------FindFirstAutosarArPackage(Root)----------------------------------------------
def ReadArxml(Arpackage,ListPdusToDelete):
    if hasattr(Arpackage, "ElementList"):
        FindPdus(Arpackage, ListPdusToDelete)
        
    for child_arPackage in Arpackage.ArPackageList:
        if child_arPackage is not None:
           ReadArxml(child_arPackage, ListPdusToDelete)





#----------------------------------------------------------------------------------------------------------------
#-----------------------------------FindAutosar(Fibexelements)---------------------------------------------------
def FindPdus(mainPackage, ListPdusToDelete):

    try:
        for element in mainPackage.ElementList:                                
            if type(element) is VISignalIPdu:                
                AddPduToCollection(element,"ISignalIPdus", ListPdusToDelete)

            elif type(element) is VMultiplexedIPdu:                
                AddPduToCollection(element,"MultiplexedIPdus", ListPdusToDelete)

            elif type(element) is VUserDefinedPdu:                
                AddPduToCollection(element,"UserDefinedPdus", ListPdusToDelete)

            elif type(element) is VUserDefinedIPdu:                
                AddPduToCollection(element,"UserDefinedIPdus", ListPdusToDelete)

            elif type(element) is VNPdu:                
                AddPduToCollection(element,"NPdus", ListPdusToDelete)

            elif type(element) is VGeneralPurposePdu:                
                AddPduToCollection(element,"GeneralPurposePdus", ListPdusToDelete)

            elif type(element) is VGeneralPurposeIPdu:                
                AddPduToCollection(element,"GeneralPurposeIPdus", ListPdusToDelete)

            elif type(element) is VXcpPdu:                
                AddPduToCollection(element,"XcpPdus", ListPdusToDelete)

            elif type(element) is VNmPdu:                
                AddPduToCollection(element,"NmPdus", ListPdusToDelete)
            
            elif type(element) is VSecuredIPdu:                
                AddPduToCollection(element,"SecuredIPdus", ListPdusToDelete)

            elif type(element) is VDcmIPdu:                
                AddPduToCollection(element,"DcmIPdus", ListPdusToDelete)
                    
    except Exception, e: 
           print("<p>Error: %s</p>" % str(e))

    return mainPackage


#----------------------------------------------------------------------------------------------------------------
#-----------------------------------ISignalIPdus-----------------------------------------------------------------
def AddPduToCollection(element, PduType, ListPdusToDelete):
    for l in range(ListPdusToDelete.Count):
    #for PduToDelete in ListPdusToDelete:
        if ListPdusToDelete[l][0] == PduType:
            #read next attribute which contains the answer yes
            #or no, save it in the Pdu List
            ListPdusToDelete[l].append(element)                                                                                  
            break




def ReadSpecificationXmlFile(ListPdusToDelete):
    AbsoluteDirectoryPath = os.path.dirname(os.path.abspath(__file__))
    XmlFilepath = AbsoluteDirectoryPath + "\UserVariablesConfig.xml"
    doc = XDocument.Load(XmlFilepath)
    if doc is not None:
       xlm = doc.Root
       for child in xlm.Nodes():
           if hasattr(child, "HasAttributes"):
              if child.HasAttributes:
                 for attribute in child.Attributes():
                     for l in range(ListPdusToDelete.Count):
                       #for PduToDelete in ListPdusToDelete:
                         if ListPdusToDelete[l][0] == attribute.Value:
                           #read next attribute which contains the answer yes or no, save it in the Pdu List
                           ListPdusToDelete[l].append(attribute.NextAttribute.Value)                                                                                  
                           break
                                                                

def CreateListPdusToFind():
    PdusToDelete = []
    PdusToDelete.append([])
    PdusToDelete[0].append("ISignalIPdus")
    PdusToDelete.append([])
    PdusToDelete[1].append("MultiplexedIPdus")
    PdusToDelete.append([])
    PdusToDelete[2].append("UserDefinedPdus")
    PdusToDelete.append([])
    PdusToDelete[3].append("UserDefinedIPdus")
    PdusToDelete.append([])
    PdusToDelete[4].append("GeneralPurposePdus")     	 
    PdusToDelete.append([])
    PdusToDelete[5].append("SecuredIPdus")  
    PdusToDelete.append([])
    PdusToDelete[6].append("DcmIPdus")  
    PdusToDelete.append([])
    PdusToDelete[7].append("XcpPdus")  
    PdusToDelete.append([])
    PdusToDelete[8].append("NmPdus")  
    PdusToDelete.append([])
    PdusToDelete[9].append("GeneralPurposeIPdus")  
    return PdusToDelete


def DeletePdus(ListPdusToDelete, logFile):


     for l in range(ListPdusToDelete.Count):                   
         
         #If ISignalIpdus have to be deleted call the function to start the procedure
         ##############################################################################                                
         if ListPdusToDelete[l][0] == "ISignalIPdus" and ListPdusToDelete[l][1] == "yes":
            DeletedISignalIPdus = DeleteISignalIPdus(ListPdusToDelete[l], logFile) 
            
         ##############################################################################


         #If MultiplexedIPdus have to be deleted call the function to start the procedure
         ##############################################################################                                
         if ListPdusToDelete[l][0] == "MultiplexedIPdus" and ListPdusToDelete[l][1] == "yes":
            DeletedMultiplexedIPdus = DeleteMultiplexedIPdus(ListPdusToDelete[l], logFile)    

         ##############################################################################


         #If UserDefinedPdus have to be deleted call the function to start the procedure
         ##############################################################################                                
         if ListPdusToDelete[l][0] == "UserDefinedPdus" and ListPdusToDelete[l][1] == "yes":
            DeletedUserDefinedPdus = DeleteUserDefinedPdus(ListPdusToDelete[l], logFile)    
         ##############################################################################


         #If UserDefinedIPdus have to be deleted call the function to start the procedure
         ##############################################################################                                
         if ListPdusToDelete[l][0] == "UserDefinedIPdus" and ListPdusToDelete[l][1] == "yes":
            DeletedUserDefinedIPdus = DeleteUserDefinedIPdus(ListPdusToDelete[l], logFile)    
         ##############################################################################


         #If NPdus have to be deleted call the function to start the procedure
         ##############################################################################                                
         if ListPdusToDelete[l][0] == "NPdus" and ListPdusToDelete[l][1] == "yes":
            DeleteNPdus(ListPdusToDelete[l], logFile)    
         ##############################################################################


         #If GeneralPurposePdus have to be deleted call the function to start the procedure
         ##############################################################################                                
         if ListPdusToDelete[l][0] == "GeneralPurposePdus" and ListPdusToDelete[l][1] == "yes":
            DeleteGeneralPurposePdus(ListPdusToDelete[l], logFile)    
         ##############################################################################


         #If GeneralPurposeIPdus have to be deleted call the function to start the procedure
         ##############################################################################                                
         if ListPdusToDelete[l][0] == "GeneralPurposeIPdus" and ListPdusToDelete[l][1] == "yes":
            DeleteGeneralPurposeIPdus(ListPdusToDelete[l], logFile)    
         ##############################################################################

         #If XcpPdus have to be deleted call the function to start the procedure
         ##############################################################################                                
         if ListPdusToDelete[l][0] == "XcpPdus" and ListPdusToDelete[l][1] == "yes":
            DeleteXcpPdus(ListPdusToDelete[l],logFile)    
         ##############################################################################


         #If NMPdus have to be deleted call the function to start the procedure
         ##############################################################################                                
         if ListPdusToDelete[l][0] == "NmPdus" and ListPdusToDelete[l][1] == "yes":
            DeleteNmPdus(ListPdusToDelete[l], logFile)    
         ##############################################################################


         #If SecuredIPdus have to be deleted call the function to start the procedure
         ##############################################################################                                
         if ListPdusToDelete[l][0] == "SecuredIPdus" and ListPdusToDelete[l][1] == "yes":
            DeletedSecuredIPdus = DeleteSecuredIPdus(ListPdusToDelete[l], logFile)    
         ##############################################################################


         #If DcmIPdus have to be deleted call the function to start the procedure
         ##############################################################################                                
         if ListPdusToDelete[l][0] == "DcmIPdus" and ListPdusToDelete[l][1] == "yes":
            DeletedDcmIPdu = DeleteDcmIPdus(ListPdusToDelete[l], logFile)    
         ##############################################################################

def DeleteISignalIPdus(ISignalIPduCollection, logFile):
    try:
        ISignalToIPduMappingsCollection = set()
        PduToFrameMappingCollection = set()
        EndToEndProtectionCollection = set()    
        PduTriggeringCollection = set()
        ISignalIpduGroupCollection = set()    
        ISignalTriggeringCollection = set()
        ISignalPortCollection = set()
        FrameTriggeringCollection = set()
        ContainerIPduCollection = set()
        DynamicPartAlternativeCollectionMultiplexedIPdus = set()
        FrameCollection = set()
        FramePortCollection = set()
        SourceTargetIPduMappingsCollection = set()
        SourceTargetISignalMappingsCollection = set()
        AssociatedComIPduGroupRefsCollection = set() #EcuInstance ISignalIPduGroups
        PncGroupRefCollection = set()  #SystemMapping --> ISignalIPduGroups
        TPConnectionsCollection = set()
        ApplicationEntriesCollection = set()
        J1939TpPgCollection = set()

        counter = 0
        for CollectedISignalIPdu in ISignalIPduCollection:


            if type(CollectedISignalIPdu) is VISignalIPdu:
           

            
               #Collect ISignaltoPduMappings to delete also ISignals later.
               ##############################################################################

               for ISignalToIPduMapping in CollectedISignalIPdu.ISignalToPduMappingList:
                   ISignalToIPduMappingsCollection.add(ISignalToIPduMapping)

               ##############################################################################                        
            
               for referencedby in CollectedISignalIPdu.ReferencedFromList:
           
           
               #Collect referenced IPduToFrameMappings
               ##############################################################################               
               #If the ISignalIPdu is not being referenced by any IPduToFrameMapping the reason could be that :
               #a) the ISignalIPdu is being sent by a MultiplexedIPdu
               #b) the ISignalIPdu is being sent over an Ethernet Bus (Socket Connection)
               #c) the ISignalIPdu is packed in IContainerIPdus
               #d) the ISignalIPdu was wrongly modelled , because its not linked to any Frame           

                   if type(referencedby.Owner) is VPduToFrameMapping:
                      PduToFrameMappingCollection.add(referencedby.Owner)
                  
               ##############################################################################



               #Collect referenced EndToEndProtection
               ##############################################################################

                   elif type(referencedby.Owner) is VEndToEndProtectionISignalIPdu:
                      EndToEndProtectionCollection.add(referencedby.Owner)
                   
               ##############################################################################


               
               #Collect referenced IPduTriggerings
               ##############################################################################

                   elif type(referencedby.Owner) is VPduTriggering:
                      PduTriggeringCollection.add(referencedby.Owner)
                   
               ##############################################################################



               #Collect referenced ISignalIPduRefConditional ---> ISignalIPduRefConditional.Owner = ISignalIPduGroup
               ##############################################################################

                   elif type(referencedby.Owner) is VISignalIPduRefConditional:
                      ISignalIpduGroupCollection.add(referencedby.Owner.Owner)
                   
               ##############################################################################


               #Collect SystemRefs
               ##############################################################################

                   elif type(referencedby) is VFibexElement_Ref:
                        SystemFibexElement = referencedby.Owner
                        SystemFibexElement.FibexElementSpecified = False #Delete the reference
                   
               ##############################################################################


               #Collect DynamicPart (MultiplexedIPdus)
               ##############################################################################

                   elif type(referencedby.Owner) is VDynamicPartAlternative:
                        DynamicPartAlternativeCollectionMultiplexedIPdus.add(referencedby.Owner)
                   
               ##############################################################################



               #Collect TPConfigs (MultiplexedIPdus)
               ##############################################################################
           
                   elif isinstance(referencedby.Owner, ITpConnection):
                        TPConnectionsCollection.add(referencedby.Owner)
                   
               ##############################################################################

               #Collect
               ##############################################################################
           
                   elif type(referencedby.Owner) is VJ1939TpPg:
                        J1939TpPgCollection.add(referencedby.Owner.Owner)                      
               ##############################################################################           

    
    
        #Now iterate over the collected ISignalToIPduMappings and delete the referenced ISignals or ISignalGroups
        ########################################################################################################################################################################################################################################################################################################################

        for ISignalToIPduMapping in ISignalToIPduMappingsCollection:

            #ISignalRef Case
            ####################################################################################################################################################################################################################################
            if ISignalToIPduMapping.ISignalSpecified == True:
           
               #Find ISignal and delete it
               FindISignal = model.Find(ISignalToIPduMapping.ISignal.Value)
               if not FindISignal is None and FindISignal.Count >0:
                  
                  #Delete it!
                  ISignalToDelete = FindISignal[0]
               
               
                  #Before the ISignal is deleted the following referenced elements can be deleted
                  #(FibexElements) ----> of the ISignal in System
                  #ISignalTriggering ---> which is located in the Cluster ( Can, Ethernet, FlexRay, Ethernet)
                  #SystemSignal  (maybe)
                  ###########################################################################################################################################################################



                  for referencedby in ISignalToDelete.ReferencedFromList:
                   
                       #delete FibexElement
                       #########################################################
                   
                       if type(referencedby) is VFibexElement_Ref:
                          SystemFibexElement = referencedby
                          SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference
                       #########################################################

                   
                   
                       #delete ISignalTriggering and ISignalPort ( referenced ISignalTriggering in ISignal)
                       #########################################################
                       elif type(referencedby.Owner) is VISignalTriggering:
                          ISignalTriggering = referencedby.Owner
                      
                          #Add the ISignalTriggering to the Collection
                          ISignalTriggeringCollection.add(ISignalTriggering)

                          #find out whether an ISignalPort exists in the ISignalTriggering, if so , then delete it.
                          if ISignalTriggering.ISignalPortList.Count >0:                         
                             for ISignalPort in ISignalTriggering.ISignalPortList:
                                 FindISignalPort = model.Find(ISignalPort.Value)
                                 if not FindISignalPort is None:
                                    ISignalPortCollection.add(FindISignalPort[0])
                       #########################################################



                  #Finally Delete the ISignal
                  PackageFromISignal = ISignalToDelete.Parent
                  PackageFromISignal.RemoveElement(ISignalToDelete)              
            ####################################################################################################################################################################################################################################

       

            #ISignalGroupRef Case
            ####################################################################################################################################################################################################################################
            #if ISignalToIPduMapping
            if ISignalToIPduMapping.ISignalGroupSpecified == True:
           
               #Find ISignal and delete it
               FindISignalGroup = model.Find(ISignalToIPduMapping.ISignalGroup.Value)
               if not FindISignalGroup is None and FindISignalGroup.Count > 0:
                   #Delete it!
                  ISignalGroupToDelete = FindISignalGroup[0]

                  #Before the ISignalGroup is deleted the following referenced elements can be deleted
                  #(FibexElements) ----> of the ISignalGroup in System
                  #ISignalTriggering ---> which is located in the Cluster ( Can, Ethernet, FlexRay, Ethernet)
                  #SystemSignalGroup  (maybe)
                  ################################################################################################################
              
              
                  for referencedby in ISignalGroupToDelete.ReferencedFromList:
                   
                       #delete FibexElement
                       #########################################################
                   
                       if type(referencedby) is VFibexElement_Ref:
                          SystemFibexElement = referencedby
                          SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference
                       #########################################################

                   
                   
                       #delete ISignalTriggering and ISignalPort ( referenced ISignalTriggering in ISignalGroup)
                       #########################################################
                       elif type(referencedby.Owner) is VISignalTriggering:
                          ISignalTriggering = referencedby.Owner

                          #Add the ISignalTriggering to the Collection
                          ISignalTriggeringCollection.add(ISignalTriggering)
                      
                          #find out whether an ISignalPort exists in the ISignalTriggering, if so , then delete it.
                          if ISignalTriggering.ISignalPortList.Count >0:
                             for ISignalPort in ISignalTriggering.ISignalPortList:
                                 FindISignalPort = model.Find(ISignalPort.Value)
                                 if not FindISignalPort is None:
                                    ISignalPortCollection.add(FindISignalPort[0])
                       #########################################################



                  #Finally Delete the ISignalGroup
                  PackageFromISignalGroup = ISignalGroupToDelete.Parent
                  PackageFromISignalGroup.RemoveElement(ISignalGroupToDelete)
            ################################################################################################################

        
            #DeleteISignalToPduMapping
    
            ISignalToIPduMapping.Owner.RemoveISignalToPduMapping(ISignalToIPduMapping)
            ####################################################################################################################################################################################################################################

        #Now Delete the collected information:

        ##############################################################################
    
    
        #Delete the collected TPConnections

        ##############################################################################           
        for TPConnection in TPConnectionsCollection:
            TPConnection.Owner.RemoveTpConnection(TPConnection)
        
        ##############################################################################

    
        #Delete the collected J1939 TPConnections

        ##############################################################################           
        for J1939TPConnection in J1939TpPgCollection:
            if hasattr(J1939TPConnection.Owner, "RemoveTpConnection"):
               J1939TPConnection.Owner.RemoveTpConnection(J1939TPConnection)
        
        ##############################################################################


    
    
        #Delete the collected ISignalTriggerings
        for ISignalTriggering in ISignalTriggeringCollection:
        
            #Collect ISignalMappings before deleting the collected ISignalTriggerings
            ##############################################################################
            for referencedby in ISignalTriggering.ReferencedFromList:
                if type(referencedby.Owner) is VISignalMapping:
                   SourceTargetISignalMappingsCollection.add(referencedby.Owner)
            ##############################################################################

            ISignalTriggering.Owner.RemoveISignalTriggering(ISignalTriggering)
        ##############################################################################


        #delete collected ISignalMappings
        for ISignalMapping in SourceTargetISignalMappingsCollection:
            Gateway = ISignalMapping.Owner
            Gateway.RemoveSignalMapping(ISignalMapping)


        ##############################################################################
        #Delete the collected ISignalPorts
        for ISignalPort in ISignalPortCollection:
            ISignalPort.Owner.RemoveEcuCommPortInstance(ISignalPort)
        ##############################################################################



        #Delete the collected EndToEndProtection
        ##############################################################################
        for EndToEndProtection in EndToEndProtectionCollection:
            EndToEndProtection.Owner.RemoveEndToEndProtectionISignalIPdu(EndToEndProtection)  #--->    EndToEndProtectionSets.RemoveEndToEndProtection
                   
        ##############################################################################
             



        #Delete the collected ISignalIPduRefConditional ---> ISignalIPduRefConditional.Owner = ISignalIPduGroup
        ##############################################################################

        for ISignalIpduGroup in ISignalIpduGroupCollection:
        
            for referencedby in ISignalIpduGroup.ReferencedFromList:        
            #Delete SystemFibexElement ref
            ####################################################                                
                if type(referencedby) is VFibexElement_Ref:
                   SystemFibexElement = referencedby
                   SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference
        
                elif type(referencedby.Owner) is VPncMapping:                 
                     PncGroupRefCollection.add(referencedby)
                elif type(referencedby.Owner) is VEcuInstance:    
                     AssociatedComIPduGroupRefsCollection.add(referencedby)
    
    

            ISignalIpduGroup.Owner.RemoveElement(ISignalIpduGroup) 

        #remove the collected PncGroupRefs
        for PncGroupRef in PncGroupRefCollection:
            PncMapping = PncGroupRef.Owner
            PncMapping.RemovePncGroup(PncGroupRef)

            #remove the collected AssociatedComIPduGroupRefs
        for AssociatedComIpduGroupRef in AssociatedComIPduGroupRefsCollection:
            EcuInstance = AssociatedComIpduGroupRef.Owner                       
            EcuInstance.RemoveAssociatedComIPduGroup(AssociatedComIpduGroupRef)
                    
        ##############################################################################


        #remove the collected DynamicParts (MultiplexedIPdu)
        ##############################################################################

        for dynamicPartAlternativeISignalIPdu in DynamicPartAlternativeCollectionMultiplexedIPdus:
            dynamicPartAlternativeISignalIPdu.Owner.RemoveDynamicPartAlternative(dynamicPartAlternativeISignalIPdu)                    

        ##############################################################################

      


        for PduTriggering in PduTriggeringCollection:
        
            #if PduTriggering is located in Cluster Ethernet?
            #there are no frames , but socketconnections
            if type(PduTriggering.Owner) is VEthernetPhysicalChannel:
                 deleteSocketConnectionIPduIdentifier(PduTriggering)



            #if PduTriggering is located in FlexRay/Lin/Can Cluster?
            #frames have to be deleted, access to pdutoframemappings to delete them
            elif isinstance(PduTriggering.Owner, IPhysicalChannel):
                 deleteFrameOfPdu(PduTriggering, ContainerIPduCollection,FrameTriggeringCollection, SourceTargetIPduMappingsCollection)




        #Delete Empty ContainerIPdus and empty Frames(without PduTriggerings)
        ########################################################################################################################################################
        #Delete IContainerIPdus
        if ContainerIPduCollection.Count >0:
            for collectedContainerIPdu in ContainerIPduCollection:
                if collectedContainerIPdu.ContainedPduTriggeringList.Count == 0:
    

                    #Collect and delete references
                    ####################################################            
                    for referencedby in collectedContainerIPdu.ReferencedFromList:
                    
                        #Collect PduToFrameMapping
                        if type(referencedby.Owner) is VPduToFrameMapping:
                           PduToFrameMappingCollection.add(referencedby.Owner)


                        #Delete SystemFibexElement ref
                        ####################################################                                
                        elif type(referencedby) is VFibexElement_Ref:
                           SystemFibexElement = referencedby
                           SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference


                        #Collect PduTriggering ref
                        ####################################################                                
                        elif type(referencedby.Owner) is VPduTriggering:
                           PduTriggeringCollection.add(referencedby.Owner)
                       



                    #Now Delete ContainerIPdu
                    ####################################################            
                    collectedContainerIPdu.Owner.RemoveElement(collectedContainerIPdu)
               

        ########################################################################################################################################################    
                
                
         #delete collected empty FrameTriggerings
        ########################################################################################################            
        if FrameTriggeringCollection.Count >0:
            for frameTriggering in FrameTriggeringCollection:
                if frameTriggering.PduTriggeringList.Count == 0:
                
                    #Collect Frame and FramePorts to delete 
                    if frameTriggering.FrameSpecified == True:
                       FrameCollection.add(frameTriggering.Frame)                
                       FramePortCollection.add(frameTriggering.FramePortList)
       

        #check if the frametriggerings are being referenced by LinScheduleTables
        ########################################################################################################            
        for frameTriggering in FrameTriggeringCollection:
            for referencedby in frameTriggering.ReferencedFromList:
            
                if type(referencedby.Owner) is VApplicationEntry:              
                   ApplicationEntriesCollection.add(referencedby.Owner)


        #now delete the collected applicationEntries

        for applicationEntry in ApplicationEntriesCollection:
            applicationEntry.FrameTriggeringSpecified = False


        ########################################################################################################            




            #delete collected Frames
        for frameRef in FrameCollection:
            if type(frameRef) is VFrame_Ref:

               FindFrame = model.Find(frameRef.Value)
               if not FindFrame is None:
                  if FindFrame.Count >0:
                     Frame = FindFrame[0]  
          
                     for referencedby in Frame.ReferencedFromList:
                   
                        #delete FibexElement
                        #########################################################
                            
                        if type(referencedby) is VFibexElement_Ref:
                           SystemFibexElement = referencedby
                           SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference
                        #########################################################

                  Frame.Owner.RemoveElement(Frame)
            elif isinstance(frameRef, IFrame):
              
                 for referencedby in frameRef.ReferencedFromList:
                   
                     #delete FibexElement
                     #########################################################
                            
                     if type(referencedby) is VFibexElement_Ref:
                        SystemFibexElement = referencedby
                        SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference
                     #########################################################

                 Frame.Owner.RemoveElement(frameRef)

    
        #delete FrameTriggerings
        for frameTriggering in FrameTriggeringCollection:
            PhysicalChannel =  frameTriggering.Owner
            PhysicalChannel.RemoveFrameTriggering(frameTriggering)
        ########################################################################################################            


        #Now delete the PduToFrameMappings 
        for pduToFrameMapping in PduToFrameMappingCollection:
            Frame = pduToFrameMapping.Owner
            Frame.RemovePduToFrameMapping(pduToFrameMapping)



        #Deleted affected IPduMappings(Gateway)
        for IPduMappingSourceOrTarget in SourceTargetIPduMappingsCollection:
            Gateway = IPduMappingSourceOrTarget.Owner
            Gateway.RemoveIPduMapping(IPduMappingSourceOrTarget)        

        #DO NOT DELETE PDUTRIGGERINGS UNTIL YOU HAVE DELETED THE ISIGNALIPDUS
        #Delete the collected PduTriggerings
        for pduTriggering in PduTriggeringCollection:
            PhysicalChannel = pduTriggering.Owner
            PhysicalChannel.RemovePduTriggering(pduTriggering)

    
        #Delete ISIGNALIPDUs
    
        if  ISignalIPduCollection.Count >2:
            logFile.write("\n deleted ISignalIPdus \n")
            logFile.write("################################################### \n")
            for ISignalIPdu in ISignalIPduCollection:
                if type(ISignalIPdu) is VISignalIPdu:

                   logFile.write("{0}\n".format(ISignalIPdu.AsrPath))    
                   ISignalIPdu.Owner.RemoveElement(ISignalIPdu)
            logFile.write("################################################### \n")   
        else:
            logFile.write("\n deleted ISignalIPdus \n")
            logFile.write("################################################### \n")                
            logFile.write("the file does not contain ISignalIPdus\n")                
            logFile.write("################################################### \n")                


        return ISignalIPduCollection
    
    except Exception, e: 
        with open("{0}/error_log.txt".format(os.path.dirname(os.path.realpath(__file__))), "w") as f:
             f.write("{0}\error while deleting ISignalIPdus----------------------------------------------------\n") 
             f.write("{0}\n".format(e))
    ########################################################################################################################################################################################################################################################################################################################

def deleteSocketConnectionIPduIdentifier(PduTriggering):
    #SocketConnectionBundle = PduTriggering.Owner
    #if(SocketConnectionBundle is VEthernetPhysicalChannel):
    for referencedby in PduTriggering.ReferencedFromList:
        if type(referencedby.Owner) is  VSocketConnectionIpduIdentifier:
           SocketConnectionIpduIdentifier = referencedby.Owner           
           SocketConnectionBundle = SocketConnectionIpduIdentifier.Owner
           SocketConnectionBundle.RemovePdu(SocketConnectionIpduIdentifier)
           break

def deleteFrameOfPdu(PduTriggering, ContainerIPduCollection,FrameTriggeringCollection, SourceTargetIPduMappingsCollection):
    
    PduTriggeringgRefConditionalCollection = set()
    ContainedPduTriggeringRefCollection = set()
    

    
    #find referencedElements in PduTriggering
    ############################################################################
    for referencedby in PduTriggering.ReferencedFromList:
        if type(referencedby.Owner) is VPduTriggeringRefConditional: # .Owner --> FrameTriggering

            #delete Frame and FrameTriggering
            ####################################################            

            PduTriggeringgRefConditional = referencedby.Owner            
            FrameTriggering = PduTriggeringgRefConditional.Owner
            PduTriggeringgRefConditionalCollection.add(PduTriggeringgRefConditional)
            FrameTriggeringCollection.add(FrameTriggering)
            ####################################################

        
        elif type(referencedby.Owner) is VContainerIPdu:
        
            #delete IContainerIPduRef
            ####################################################

            ContainerIPdu = referencedby.Owner
            ContainedPduTriggeringRefCollection.add(referencedby)
            ContainerIPduCollection.add(ContainerIPdu)
        
            ####################################################

        elif type(referencedby.Owner) is VTargetIPduRef:
             SourceTargetIPduMappingsCollection.add(referencedby.Owner.Owner)

        elif type(referencedby.Owner) is VIPduMapping:            
              SourceTargetIPduMappingsCollection.add(referencedby.Owner)

    ############################################################################
    


    #Delete Collected ContainedPduTriggeringRef and PduTriggeringgRefConditional
    ########################################################################################################
    if PduTriggeringgRefConditionalCollection.Count > 0:
        for PduTriggeringRefConditional in  PduTriggeringgRefConditionalCollection:
            FrameTriggering = PduTriggeringRefConditional.Owner
            FrameTriggering.RemovePduTriggering(PduTriggeringRefConditional)                      



    if ContainerIPduCollection.Count > 0:
        for ContainedPduTriggeringRef in ContainedPduTriggeringRefCollection:
            ContainerIPdu = ContainedPduTriggeringRef.Owner                        
            ContainerIPdu.RemoveContainedPduTriggering(ContainedPduTriggeringRef)
    ########################################################################################################

 

def DeleteMultiplexedIPdus(MultiplexedIPduCollection, logFile):
    try:
        ISignalToIPduMappingsCollection = set()
        PduToFrameMappingCollection = set()
        EndToEndProtectionCollection = set()    
        PduTriggeringCollection = set()
        ISignalIpduGroupCollection = set()    
        ISignalTriggeringCollection = set()
        ISignalPortCollection = set()
        FrameTriggeringCollection = set()
        ContainerIPduCollection = set()
        DynamicPartAlternativeCollectionMultiplexedIPdus = set()
        FrameCollection = set()
        FramePortCollection = set()
        SourceTargetIPduMappingsCollection = set()
        AssociatedComIPduGroupRefsCollection = set() #EcuInstance ISignalIPduGroups
        PncGroupRefCollection = set()  #SystemMapping --> ISignalIPduGroups
        ApplicationEntriesCollection = set()

        for CollectedMultiplexedIPdu in MultiplexedIPduCollection:


            if type(CollectedMultiplexedIPdu) is VMultiplexedIPdu:
                                          
            
               for referencedby in CollectedMultiplexedIPdu.ReferencedFromList:
           
           
               #Collect referenced IPduToFrameMappings
               ##############################################################################                     

                   if type(referencedby.Owner) is VPduToFrameMapping:
                      PduToFrameMappingCollection.add(referencedby.Owner)
                  
               ##############################################################################



               
               #Collect referenced IPduTriggerings
               ##############################################################################

                   elif type(referencedby.Owner) is VPduTriggering:
                      PduTriggeringCollection.add(referencedby.Owner)                                 
               ##############################################################################



               #Collect SystemRefs
               ##############################################################################

                   elif type(referencedby) is VFibexElement_Ref:
                        SystemFibexElement = referencedby.Owner
                        SystemFibexElement.FibexElementSpecified = False #Delete the reference
                   
               ##############################################################################
      


        for PduTriggering in PduTriggeringCollection:
        
            #if PduTriggering is located in Cluster Ethernet?
            #there are no frames , but socketconnections
            if type(PduTriggering.Owner) is VEthernetPhysicalChannel:
                 deleteSocketConnectionIPduIdentifier(PduTriggering)



            #if PduTriggering is located in FlexRay/Lin/Can Cluster?
            #frames have to be deleted, access to pdutoframemappings to delete them
            elif isinstance(PduTriggering.Owner, IPhysicalChannel):
                 deleteFrameOfPdu(PduTriggering, ContainerIPduCollection,FrameTriggeringCollection, SourceTargetIPduMappingsCollection)


                
         #delete collected empty FrameTriggerings
        ########################################################################################################            
        if FrameTriggeringCollection.Count >0:
            for frameTriggering in FrameTriggeringCollection:
                if frameTriggering.PduTriggeringList.Count == 0:
                
                    #Collect Frame and FramePorts to delete 
                    if frameTriggering.FrameSpecified == True:
                       FrameCollection.add(frameTriggering.Frame)                
                       FramePortCollection.add(frameTriggering.FramePortList)


        #check if the frametriggerings are being referenced by LinScheduleTables
        ########################################################################################################            
        for frameTriggering in FrameTriggeringCollection:
            for referencedby in frameTriggering.ReferencedFromList:
            
                if type(referencedby.Owner) is VApplicationEntry:              
                   ApplicationEntriesCollection.add(referencedby.Owner)


        #now delete the collected applicationEntries

        for applicationEntry in ApplicationEntriesCollection:
            applicationEntry.FrameTriggeringSpecified = False


        ########################################################################################################   

    

            #delete collected Frames
        for frameRef in FrameCollection:
            if type(frameRef) is VFrame_Ref:

               FindFrame = model.Find(frameRef.Value)
               if not FindFrame is None:
                  if FindFrame.Count >0:
                     Frame = FindFrame[0]  
          
                     for referencedby in Frame.ReferencedFromList:
                   
                        #delete FibexElement
                        #########################################################
                            
                        if type(referencedby) is VFibexElement_Ref:
                           SystemFibexElement = referencedby
                           SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference
                        #########################################################

                  Frame.Owner.RemoveElement(Frame)
            elif isinstance(frameRef, IFrame):
              
                 for referencedby in frameRef.ReferencedFromList:
                   
                     #delete FibexElement
                     #########################################################
                            
                     if type(referencedby) is VFibexElement_Ref:
                        SystemFibexElement = referencedby
                        SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference
                     #########################################################

                 Frame.Owner.RemoveElement(frameRef)

    
        #delete FrameTriggerings
        for frameTriggering in FrameTriggeringCollection:
            PhysicalChannel =  frameTriggering.Owner
            PhysicalChannel.RemoveFrameTriggering(frameTriggering)
        ########################################################################################################            


        #Now delete the PduToFrameMappings 
        for pduToFrameMapping in PduToFrameMappingCollection:
            Frame = pduToFrameMapping.Owner
            Frame.RemovePduToFrameMapping(pduToFrameMapping)



        #Deleted affected IPduMappings(Gateway)
        for IPduMappingSourceOrTarget in SourceTargetIPduMappingsCollection:
            Gateway = IPduMappingSourceOrTarget.Owner
            Gateway.RemoveIPduMapping(IPduMappingSourceOrTarget)        

        #DO NOT DELETE PDUTRIGGERINGS UNTIL YOU HAVE DELETED THE ISIGNALIPDUS
        #Delete the collected PduTriggerings
        for pduTriggering in PduTriggeringCollection:
            PhysicalChannel = pduTriggering.Owner
            PhysicalChannel.RemovePduTriggering(pduTriggering)

    
        #Delete MultiplexedIPdus

        if MultiplexedIPduCollection.Count > 2:
           logFile.write("\n deleted MultiplexedPdus \n")
           logFile.write("################################################### \n")
           for MultiplexedIPdu in MultiplexedIPduCollection:
               if type(MultiplexedIPdu) is VMultiplexedIPdu:

                  logFile.write("{0}\n  ".format(MultiplexedIPdu.AsrPath))    
                  MultiplexedIPdu.Owner.RemoveElement(MultiplexedIPdu)
           logFile.write("################################################### \n")

        else:
            logFile.write("\n deleted MultiplexedIPdus \n")
            logFile.write("################################################### \n")                
            logFile.write("the file does not contain MultiplexedIPdus\n")                
            logFile.write("################################################### \n")                
        return MultiplexedIPduCollection

    except Exception, e: 
        with open("{0}/error_log.txt".format(os.path.dirname(os.path.realpath(__file__))), "w") as f:
             f.write("{0}\error while deleting MultiplexedIPdus----------------------------------------------------\n") 
             f.write("{0}\n".format(e))
    ########################################################################################################################################################################################################################################################################################################################

def DeleteDcmIPdus(DcmIPduCollection, logFile):
    try:
        DcmIPdusToDelete = set() #collect DcmIPdus which are being referenced by PduToFrameMappings
        PduToFrameMappingCollection = set()
        PduTriggeringCollection = set()
        ContainerIPduCollection = set()
        FrameTriggeringCollection = set()
        SourceTargetIPduMappingsCollection = set()
        FrameCollection = set()
        FramePortCollection = set()
        DiagnosticConnectionCollection = set()
        DiagnosticConnectionRefInServiceTableCollection = set()
        ApplicationEntriesCollection = set() #Lin ScheduleTables

        for DcmIPdu in DcmIPduCollection:
            if DcmIPduCollection.Count >2:

           
               if type(DcmIPdu) is VDcmIPdu:
                      
                  for referencedby in DcmIPdu.ReferencedFromList:
                

                     #collect DcmIPdus which are being referenced by PduToFrameMappings
                     ##############################################################################                     

                     if type(referencedby.Owner) is VPduToFrameMapping:
                        PduToFrameMappingCollection.add(referencedby.Owner)
                        DcmIPdusToDelete.add(DcmIPdu)
                        break
                     ##############################################################################

        #iterate over the found DcmIPdus which are being referenced by PduToFrameMappings
        ##############################################################################                     
        for DcmIPduToDelete in DcmIPdusToDelete:

            for referencedby in DcmIPduToDelete.ReferencedFromList:
            #delete reference FibexElement in System
            ##############################################################################                     

                if type(referencedby) is VFibexElement_Ref:
                   SystemFibexElement = referencedby.Owner
                   SystemFibexElement.FibexElementSpecified = False #Delete the reference
                  
            ##############################################################################
           
           
            #Collect referenced IPduTriggerings
            ##############################################################################

                elif type(referencedby.Owner) is VPduTriggering:
                     PduTriggeringCollection.add(referencedby.Owner)
                   
            ##############################################################################
       

        ################################################################################################



        for PduTriggering in PduTriggeringCollection:
        
        #if PduTriggering is located in Cluster Ethernet?
        #there are no frames , but socketconnections
            if type(PduTriggering.Owner) is VEthernetPhysicalChannel:
               deleteSocketConnectionIPduIdentifier(PduTriggering)



        #if PduTriggering is located in FlexRay/Lin/Can Cluster?
        #frames have to be deleted, access to pdutoframemappings to delete them
            elif isinstance(PduTriggering.Owner, IPhysicalChannel):
                 deleteFrameOfPdu(PduTriggering, ContainerIPduCollection,FrameTriggeringCollection, SourceTargetIPduMappingsCollection)

         
             
            #Collect referenced DiagnostiConnection
            ##############################################################################
            for referencedby in PduTriggering.ReferencedFromList:
                 if type(referencedby.Owner) is VDiagnosticConnection:
                      DiagnosticConnectionCollection.add(referencedby.Owner)                   
            ##############################################################################   


        #Delete Diagnostic Connections 
        ##############################################################################        
        for DiagnosticConnection in DiagnosticConnectionCollection:
            for referencedby in DiagnosticConnection.ReferencedFromList:
                if type(referencedby.Owner) is VDiagnosticConnectionRefConditional:
                    DiagnosticConnectionRefInServiceTableCollection.add(referencedby.Owner)
                
                
            DiagnosticConnection.Owner.RemoveElement(DiagnosticConnection)


        #delete the collected references in ServiceTableCollection
        for DiafnosticConnectionRefConditional in DiagnosticConnectionRefInServiceTableCollection:
            DiagnosticServiceTable = DiafnosticConnectionRefConditional.Owner
            DiagnosticServiceTable.RemoveDiagnosticConnection(DiafnosticConnectionRefConditional)
        ##############################################################################        

         #delete collected empty FrameTriggerings
        ########################################################################################################            
        if FrameTriggeringCollection.Count >0:
            for frameTriggering in FrameTriggeringCollection:
                if frameTriggering.PduTriggeringList.Count == 0:
                
                    #Collect Frame and FramePorts to delete 
                    if frameTriggering.FrameSpecified == True:
                       FrameCollection.add(frameTriggering.Frame)                
                       if not frameTriggering.FramePortList is None:
                          FramePortCollection.add(frameTriggering.FramePortList)

    
    
        #check if the frametriggerings are being referenced by LinScheduleTables
        ########################################################################################################            
        for frameTriggering in FrameTriggeringCollection:
            for referencedby in frameTriggering.ReferencedFromList:
            
                if type(referencedby.Owner) is VApplicationEntry:              
                   ApplicationEntriesCollection.add(referencedby.Owner)


        #now delete the collected applicationEntries

        for applicationEntry in ApplicationEntriesCollection:
            applicationEntry.FrameTriggeringSpecified = False


        ########################################################################################################   




        #delete FrameTriggerings
        for frameTriggering in FrameTriggeringCollection:
            PhysicalChannel =  frameTriggering.Owner
            PhysicalChannel.RemoveFrameTriggering(frameTriggering)
        ##############################################################################################   


        #Now delete the PduToFrameMappings 
        for pduToFrameMapping in PduToFrameMappingCollection:
            Frame = pduToFrameMapping.Owner
            FrameCollection.add(Frame)
            Frame.RemovePduToFrameMapping(pduToFrameMapping)
        
    
        ##############################################################################################
            #delete collected Frames
        for frameRef in FrameCollection:
            if type(frameRef) is VFrame_Ref:

               FindFrame = model.Find(frameRef.Value)
               if not FindFrame is None:
                  if FindFrame.Count >0:
                     Frame = FindFrame[0]  
          
                     for referencedby in Frame.ReferencedFromList:
                   
                        #delete FibexElement
                        #########################################################
                            
                        if type(referencedby) is VFibexElement_Ref:
                           SystemFibexElement = referencedby
                           SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference
                        #########################################################

                  Frame.Owner.RemoveElement(Frame)
            elif isinstance(frameRef, IFrame):
              
                 for referencedby in frameRef.ReferencedFromList:
                   
                     #delete FibexElement
                     #########################################################
                            
                     if type(referencedby) is VFibexElement_Ref:
                        SystemFibexElement = referencedby
                        SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference
                     #########################################################

                 Frame.Owner.RemoveElement(frameRef)

        #Deleted affected IPduMappings(Gateway) if there were collected
        for IPduMappingSourceOrTarget in SourceTargetIPduMappingsCollection:
            Gateway = IPduMappingSourceOrTarget.Owner
            Gateway.RemoveIPduMapping(IPduMappingSourceOrTarget)        

        #DO NOT DELETE PDUTRIGGERINGS UNTIL YOU HAVE DELETED THE ISIGNALIPDUS
        #Delete the collected PduTriggerings
        for pduTriggering in PduTriggeringCollection:
            PhysicalChannel = pduTriggering.Owner
            PhysicalChannel.RemovePduTriggering(pduTriggering)

    
        #Delete the DcmIPdus
        ########################################################################################
    

        if DcmIPdusToDelete.Count > 0:
           logFile.write("\n deleted DcmIPdus \n")
           logFile.write("################################################### \n")    
           for DcmIPdu in DcmIPdusToDelete:
               logFile.write("{0}\n  ".format(DcmIPdu.AsrPath))    
               DcmIPdu.Owner.RemoveElement(DcmIPdu)
           logFile.write("################################################### \n")


        else: 
           logFile.write("\n deleted DcmIPdus \n")
           logFile.write("################################################### \n")    
           logFile.write("No DcmIpdus which match the criteria to be deleted were found in the file \n")    
           logFile.write("################################################### \n")
           if DcmIPduCollection.Count == 2: #it means 0 
              logFile.write("the file does not contain DcmIPdus \n")    
        return DcmIPdusToDelete

    except Exception, e: 
        with open("{0}/error_log.txt".format(os.path.dirname(os.path.realpath(__file__))), "w") as f:
             f.write("{0}\error while deleting DcmIPdus----------------------------------------------------\n") 
             f.write("{0}\n".format(e))

def DeleteUserDefinedPdus(UserDefinePduCollection, logFile):
    try:
        if UserDefinePduCollection.Count >2:
           for UserDefinedPdu in UserDefinePduCollection:
            
               logFile.write("\n deleted UserDefinedPdus \n")
               logFile.write("################################################### \n")        
               if type(UserDefinedPdu) is VUserDefinedPdu:
                      
                  for referencedby in UserDefinedPdu.ReferencedFromList:
                    #delete reference FibexElement in System
                    ##############################################################################                     

                     if type(referencedby) is VFibexElement_Ref:
                       SystemFibexElement = referencedby.Owner
                       SystemFibexElement.FibexElementSpecified = False #Delete the reference
                  
                    ##############################################################################

         
                  logFile.write("{0}\n  ".format(UserDefinedPdu.AsrPath))  
                  logFile.write("################################################### \n")
                  UserDefinedPdu.Owner.RemoveElement(UserDefinedPdu)
        else:
            logFile.write("\n deleted UserDefinedPdus \n")
            logFile.write("################################################### \n")        
            logFile.write("the file does not contain UserDefinedPdus \n")        
            logFile.write("################################################### \n")        
        return UserDefinePduCollection

    except Exception, e: 
        with open("{0}/error_log.txt".format(os.path.dirname(os.path.realpath(__file__))), "w") as f:
             f.write("{0}\error while deleting UserDefinedPdus----------------------------------------------------\n") 
             f.write("{0}\n".format(e))

def DeleteUserDefinedIPdus(UserDefineIPduCollection, logFile):
    try:
        if UserDefineIPduCollection.Count >2:
           for UserDefinedIPdu in UserDefineIPduCollection:
            
               logFile.write("\n deleted UserDefinedIPdus \n")
               logFile.write("################################################### \n")        
               if type(UserDefinedIPdu) is VUserDefinedIPdu:
                      
                  for referencedby in UserDefinedIPdu.ReferencedFromList:
                    #delete reference FibexElement in System
                    ##############################################################################                     

                     if type(referencedby) is VFibexElement_Ref:
                       SystemFibexElement = referencedby.Owner
                       SystemFibexElement.FibexElementSpecified = False #Delete the reference
                  
                    ##############################################################################

         
                  logFile.write("{0}\n  ".format(UserDefinedIPdu.AsrPath))  
                  logFile.write("################################################### \n")
                  UserDefinedIPdu.Owner.RemoveElement(UserDefinedIPdu)
        else:
            logFile.write("\n deleted UserDefinedIPdus \n")
            logFile.write("################################################### \n")        
            logFile.write("the file does not contain UserDefinedIPdus \n")        
            logFile.write("################################################### \n")        
        return UserDefineIPduCollection
    except Exception, e: 
        with open("{0}/error_log.txt".format(os.path.dirname(os.path.realpath(__file__))), "w") as f:
             f.write("{0}\error while deleting UserDefinedIPdus----------------------------------------------------\n") 
             f.write("{0}\n".format(e))

def DeleteNPdus(NPduCollection, logFile):
    print ""


def DeleteGeneralPurposePdus(GeneralPurposePduCollection, logFile):    
    try:
        GeneralPurposePdusToDelete = set()
        PduToFrameMappingCollection = set()
        GlobalTimeDomainCollection = set()
        PduTriggeringCollection = set()
        ContainerIPduCollection = set()
        FrameTriggeringCollection = set()
        SourceTargetIPduMappingsCollection = set()
        FrameCollection = set()
        FramePortCollection = set()
        for l in range(GeneralPurposePduCollection.Count):
    
            if type(GeneralPurposePduCollection[l]) is  VGeneralPurposePdu:
               Category = str(format(GeneralPurposePduCollection[l].Category))
               if not Category == "DoIP":            
                  GeneralPurposePdusToDelete.add(GeneralPurposePduCollection[l])                       

    
        #Delete the found GeneralPurposePdus which are not from the category DoIP
        ##############################################################################################
        for GeneralPurposePdu in GeneralPurposePdusToDelete:
                
            for referencedby in GeneralPurposePdu.ReferencedFromList:
                if type(referencedby.Owner) is  VGlobalTimeDomain:
                   GlobalTimeDomainCollection.add(referencedby.Owner)                  
               
               #Collect referenced IPduToFrameMappings
               ##############################################################################                     

                elif type(referencedby.Owner) is VPduToFrameMapping:
                     PduToFrameMappingCollection.add(referencedby.Owner)
                  
               ##############################################################################

               #delete reference FibexElement in System
               ##############################################################################                     

                elif type(referencedby) is VFibexElement_Ref:
                     SystemFibexElement = referencedby.Owner
                     SystemFibexElement.FibexElementSpecified = False #Delete the reference
                  
               ##############################################################################
           
           
               #Collect referenced IPduTriggerings
               ##############################################################################

                elif type(referencedby.Owner) is VPduTriggering:
                     PduTriggeringCollection.add(referencedby.Owner)
                   
               ##############################################################################
    

        #now delete the collected GlobalTimeDomain
        ################################################################################################
        for GlobalTime in GlobalTimeDomainCollection:
            GlobalTime.Owner.RemoveElement(GlobalTime)


        ################################################################################################


        ################################################################################################

        for PduTriggering in PduTriggeringCollection:
        
        #if PduTriggering is located in Cluster Ethernet?
        #there are no frames , but socketconnections
            if type(PduTriggering.Owner) is VEthernetPhysicalChannel:
               deleteSocketConnectionIPduIdentifier(PduTriggering)



        #if PduTriggering is located in FlexRay/Lin/Can Cluster?
        #frames have to be deleted, access to pdutoframemappings to delete them
            elif isinstance(PduTriggering.Owner, IPhysicalChannel):
                 deleteFrameOfPdu(PduTriggering, ContainerIPduCollection,FrameTriggeringCollection, SourceTargetIPduMappingsCollection)


        ##############################################################################################

         #delete collected empty FrameTriggerings
        ########################################################################################################            
        if FrameTriggeringCollection.Count >0:
            for frameTriggering in FrameTriggeringCollection:
                if frameTriggering.PduTriggeringList.Count == 0:
                
                    #Collect Frame and FramePorts to delete 
                    if frameTriggering.FrameSpecified == True:
                       FrameCollection.add(frameTriggering.Frame)                
                       if not frameTriggering.FramePortList is None:
                          FramePortCollection.add(frameTriggering.FramePortList)

    
    
        #delete FrameTriggerings
        for frameTriggering in FrameTriggeringCollection:
            PhysicalChannel =  frameTriggering.Owner
            PhysicalChannel.RemoveFrameTriggering(frameTriggering)
        ##############################################################################################   


        #Now delete the PduToFrameMappings 
        for pduToFrameMapping in PduToFrameMappingCollection:
            Frame = pduToFrameMapping.Owner
            FrameCollection.add(Frame)
            Frame.RemovePduToFrameMapping(pduToFrameMapping)
        
    
        ##############################################################################################
            #delete collected Frames
        for frameRef in FrameCollection:
            if type(frameRef) is VFrame_Ref:

               FindFrame = model.Find(frameRef.Value)
               if not FindFrame is None:
                  if FindFrame.Count >0:
                     Frame = FindFrame[0]  
          
                     for referencedby in Frame.ReferencedFromList:
                   
                        #delete FibexElement
                        #########################################################
                            
                        if type(referencedby) is VFibexElement_Ref:
                           SystemFibexElement = referencedby
                           SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference
                        #########################################################

                  Frame.Owner.RemoveElement(Frame)
            elif isinstance(frameRef, IFrame):
        
              
                 for referencedby in frameRef.ReferencedFromList:
                   
                     #delete FibexElement
                     #########################################################
                            
                     if type(referencedby) is VFibexElement_Ref:
                        SystemFibexElement = referencedby
                        SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference
                     #########################################################

                 Frame.Owner.RemoveElement(frameRef)

        #Deleted affected IPduMappings(Gateway) if there were collected
        for IPduMappingSourceOrTarget in SourceTargetIPduMappingsCollection:
            Gateway = IPduMappingSourceOrTarget.Owner
            Gateway.RemoveIPduMapping(IPduMappingSourceOrTarget)        

        #DO NOT DELETE PDUTRIGGERINGS UNTIL YOU HAVE DELETED THE ISIGNALIPDUS
        #Delete the collected PduTriggerings
        for pduTriggering in PduTriggeringCollection:
            PhysicalChannel = pduTriggering.Owner
            PhysicalChannel.RemovePduTriggering(pduTriggering)

    
        #Delete the GeneralPurposePdus
        ########################################################################################
        if GeneralPurposePduCollection.Count > 2:
           logFile.write("\n deleted GeneralPurposePdus \n")
           logFile.write("################################################### \n")
           for GeneralPurposePdu in GeneralPurposePduCollection:
               if type(GeneralPurposePdu) is VGeneralPurposePdu:

                  logFile.write("{0}\n  ".format(GeneralPurposePdu.AsrPath))    
                  GeneralPurposePdu.Owner.RemoveElement(GeneralPurposePdu)
           logFile.write("################################################### \n")
        else:
           logFile.write("\n deleted GeneralPurposePdus \n")
           logFile.write("################################################### \n")
           logFile.write("The file does not contain GeneralPurposePdus \n")
           logFile.write("################################################### \n")
        return GeneralPurposePduCollection

    except Exception, e: 
        with open("{0}/error_log.txt".format(os.path.dirname(os.path.realpath(__file__))), "w") as f:
             f.write("{0}\error while deleting GeneralPurposePdus----------------------------------------------------\n") 
             f.write("{0}\n".format(e))



def DeleteGeneralPurposeIPdus(GeneralPurposeIPduCollection, logFile):    
    try:
        GeneralPurposeIPdusToDelete = set()
        PduToFrameMappingCollection = set()
        GlobalTimeDomainCollection = set()
        PduTriggeringCollection = set()
        ContainerIPduCollection = set()
        FrameTriggeringCollection = set()
        SourceTargetIPduMappingsCollection = set()
        FrameCollection = set()
        FramePortCollection = set()
        for l in range(GeneralPurposeIPduCollection.Count):
    
            if type(GeneralPurposeIPduCollection[l]) is  VGeneralPurposeIPdu:
               Category = str(format(GeneralPurposeIPduCollection[l].Category))
               if not Category == "XCP":            
                  GeneralPurposeIPdusToDelete.add(GeneralPurposeIPduCollection[l])                       

    
        #Delete the found GeneralPurposePdus which are not from the category DoIP
        ##############################################################################################
        for GeneralPurposeIPdu in GeneralPurposeIPdusToDelete:
                
            for referencedby in GeneralPurposeIPdu.ReferencedFromList:
                if type(referencedby.Owner) is  VGlobalTimeDomain:
                   GlobalTimeDomainCollection.add(referencedby.Owner)                  
               
               #Collect referenced IPduToFrameMappings
               ##############################################################################                     

                elif type(referencedby.Owner) is VPduToFrameMapping:
                     PduToFrameMappingCollection.add(referencedby.Owner)
                  
               ##############################################################################

               #delete reference FibexElement in System
               ##############################################################################                     

                elif type(referencedby) is VFibexElement_Ref:
                     SystemFibexElement = referencedby.Owner
                     SystemFibexElement.FibexElementSpecified = False #Delete the reference
                  
               ##############################################################################
           
           
               #Collect referenced IPduTriggerings
               ##############################################################################

                elif type(referencedby.Owner) is VPduTriggering:
                     PduTriggeringCollection.add(referencedby.Owner)
                   
               ##############################################################################
    

        #now delete the collected GlobalTimeDomain
        ################################################################################################
        for GlobalTime in GlobalTimeDomainCollection:
            GlobalTime.Owner.RemoveElement(GlobalTime)


        ################################################################################################


        ################################################################################################

        for PduTriggering in PduTriggeringCollection:
        
        #if PduTriggering is located in Cluster Ethernet?
        #there are no frames , but socketconnections
            if type(PduTriggering.Owner) is VEthernetPhysicalChannel:
               deleteSocketConnectionIPduIdentifier(PduTriggering)



        #if PduTriggering is located in FlexRay/Lin/Can Cluster?
        #frames have to be deleted, access to pdutoframemappings to delete them
            elif isinstance(PduTriggering.Owner, IPhysicalChannel):
                 deleteFrameOfPdu(PduTriggering, ContainerIPduCollection,FrameTriggeringCollection, SourceTargetIPduMappingsCollection)


        ##############################################################################################

         #delete collected empty FrameTriggerings
        ########################################################################################################            
        if FrameTriggeringCollection.Count >0:
            for frameTriggering in FrameTriggeringCollection:
                if frameTriggering.PduTriggeringList.Count == 0:
                
                    #Collect Frame and FramePorts to delete 
                    if frameTriggering.FrameSpecified == True:
                       FrameCollection.add(frameTriggering.Frame)                
                       if not frameTriggering.FramePortList is None:
                          FramePortCollection.add(frameTriggering.FramePortList)

    
    
        #delete FrameTriggerings
        for frameTriggering in FrameTriggeringCollection:
            PhysicalChannel =  frameTriggering.Owner
            PhysicalChannel.RemoveFrameTriggering(frameTriggering)
        ##############################################################################################   


        #Now delete the PduToFrameMappings 
        for pduToFrameMapping in PduToFrameMappingCollection:
            Frame = pduToFrameMapping.Owner
            FrameCollection.add(Frame)
            Frame.RemovePduToFrameMapping(pduToFrameMapping)
        
    
        ##############################################################################################
            #delete collected Frames
        for frameRef in FrameCollection:
            if type(frameRef) is VFrame_Ref:

               FindFrame = model.Find(frameRef.Value)
               if not FindFrame is None:
                  if FindFrame.Count >0:
                     Frame = FindFrame[0]  
          
                     for referencedby in Frame.ReferencedFromList:
                   
                        #delete FibexElement
                        #########################################################
                            
                        if type(referencedby) is VFibexElement_Ref:
                           SystemFibexElement = referencedby
                           SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference
                        #########################################################

                  Frame.Owner.RemoveElement(Frame)
            elif isinstance(frameRef, IFrame):
        
              
                 for referencedby in frameRef.ReferencedFromList:
                   
                     #delete FibexElement
                     #########################################################
                            
                     if type(referencedby) is VFibexElement_Ref:
                        SystemFibexElement = referencedby
                        SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference
                     #########################################################

                 Frame.Owner.RemoveElement(frameRef)

        #Deleted affected IPduMappings(Gateway) if there were collected
        for IPduMappingSourceOrTarget in SourceTargetIPduMappingsCollection:
            Gateway = IPduMappingSourceOrTarget.Owner
            Gateway.RemoveIPduMapping(IPduMappingSourceOrTarget)        

        #DO NOT DELETE PDUTRIGGERINGS UNTIL YOU HAVE DELETED THE ISIGNALIPDUS
        #Delete the collected PduTriggerings
        for pduTriggering in PduTriggeringCollection:
            PhysicalChannel = pduTriggering.Owner
            PhysicalChannel.RemovePduTriggering(pduTriggering)

    
        #Delete the GeneralPurposePdus
        ########################################################################################
        if GeneralPurposeIPduCollection.Count > 2:
           logFile.write("\n deleted GeneralPurposeIPdus category XCP \n")
           logFile.write("################################################### \n")
           for GeneralPurposeIPdu in GeneralPurposeIPduCollection:
               if type(GeneralPurposeIPdu) is VGeneralPurposeIPdu:

                  logFile.write("{0}\n  ".format(GeneralPurposeIPdu.AsrPath))    
                  GeneralPurposeIPdu.Owner.RemoveElement(GeneralPurposeIPdu)
           logFile.write("################################################### \n")
        else:
           logFile.write("\n deleted GeneralPurposeIPdus \n")
           logFile.write("################################################### \n")
           logFile.write("The file does not contain GeneralPurposeIPdus \n")
           logFile.write("################################################### \n")
        return GeneralPurposeIPduCollection

    except Exception, e: 
        with open("{0}/error_log.txt".format(os.path.dirname(os.path.realpath(__file__))), "w") as f:
             f.write("{0}\error while deleting GeneralPurposeIPdus----------------------------------------------------\n") 
             f.write("{0}\n".format(e))
    ########################################################################################

def DeleteXcpPdus(XcpPduCollection, logFile):
    try:
        ISignalToIPduMappingsCollection = set()
        PduToFrameMappingCollection = set()
        PduTriggeringCollection = set()
        ISignalIpduGroupCollection = set()    
        ISignalTriggeringCollection = set()
        ISignalPortCollection = set()
        FrameTriggeringCollection = set()
        ContainerIPduCollection = set()        
        FrameCollection = set()
        FramePortCollection = set()
        SourceTargetIPduMappingsCollection = set()
        SourceTargetISignalMappingsCollection = set()
        AssociatedComIPduGroupRefsCollection = set() #EcuInstance ISignalIPduGroups
        PncGroupRefCollection = set()  #SystemMapping --> ISignalIPduGroups
        TPConnectionsCollection = set()
        ApplicationEntriesCollection = set()
        J1939TpPgCollection = set()

        counter = 0
        for CollectedXcpPdu in XcpPduCollection:


            if type(CollectedXcpPdu) is VXcpPdu:
                              
            
               for referencedby in CollectedXcpPdu.ReferencedFromList:
           
           
               #Collect referenced IPduToFrameMappings
               ##############################################################################               
               #If the ISignalIPdu is not being referenced by any IPduToFrameMapping the reason could be that :
               #a) the ISignalIPdu is being sent by a MultiplexedIPdu
               #b) the ISignalIPdu is being sent over an Ethernet Bus (Socket Connection)
               #c) the ISignalIPdu is packed in IContainerIPdus
               #d) the ISignalIPdu was wrongly modelled , because its not linked to any Frame           

                   if type(referencedby.Owner) is VPduToFrameMapping:
                      PduToFrameMappingCollection.add(referencedby.Owner)
                  
               ##############################################################################


               
               #Collect referenced IPduTriggerings
               ##############################################################################

                   elif type(referencedby.Owner) is VPduTriggering:
                      PduTriggeringCollection.add(referencedby.Owner)
                   
               ##############################################################################



               #Collect referenced ISignalIPduRefConditional ---> ISignalIPduRefConditional.Owner = ISignalIPduGroup
               ##############################################################################

                   elif type(referencedby.Owner) is VISignalIPduRefConditional:
                      ISignalIpduGroupCollection.add(referencedby.Owner.Owner)
                   
               ##############################################################################


               #Collect SystemRefs
               ##############################################################################

                   elif type(referencedby) is VFibexElement_Ref:
                        SystemFibexElement = referencedby.Owner
                        SystemFibexElement.FibexElementSpecified = False #Delete the reference
                   
               ##############################################################################




               #Collect TPConfigs (MultiplexedIPdus)
               ##############################################################################
           
                   elif isinstance(referencedby.Owner, ITpConnection):
                        TPConnectionsCollection.add(referencedby.Owner)
                   
               ##############################################################################

               #Collect
               ##############################################################################
           
                   elif type(referencedby.Owner) is VJ1939TpPg:
                        J1939TpPgCollection.add(referencedby.Owner.Owner)                      
               ##############################################################################           

    

        #Now Delete the collected information:

        ##############################################################################
    
    
        #Delete the collected TPConnections

        ##############################################################################           
        for TPConnection in TPConnectionsCollection:
            TPConnection.Owner.RemoveTpConnection(TPConnection)
        
        ##############################################################################

    
        #Delete the collected J1939 TPConnections

        ##############################################################################           
        for J1939TPConnection in J1939TpPgCollection:
            if hasattr(J1939TPConnection.Owner, "RemoveTpConnection"):
               J1939TPConnection.Owner.RemoveTpConnection(J1939TPConnection)
        
        ##############################################################################


    
    
        #Delete the collected ISignalTriggerings
        for ISignalTriggering in ISignalTriggeringCollection:
        
            #Collect ISignalMappings before deleting the collected ISignalTriggerings
            ##############################################################################
            for referencedby in ISignalTriggering.ReferencedFromList:
                if type(referencedby.Owner) is VISignalMapping:
                   SourceTargetISignalMappingsCollection.add(referencedby.Owner)
            ##############################################################################

            ISignalTriggering.Owner.RemoveISignalTriggering(ISignalTriggering)
        ##############################################################################


        #delete collected ISignalMappings
        for ISignalMapping in SourceTargetISignalMappingsCollection:
            Gateway = ISignalMapping.Owner
            Gateway.RemoveSignalMapping(ISignalMapping)


        ##############################################################################
        #Delete the collected ISignalPorts
        for ISignalPort in ISignalPortCollection:
            ISignalPort.Owner.RemoveEcuCommPortInstance(ISignalPort)
        ##############################################################################
           


        #Delete the collected ISignalIPduRefConditional ---> ISignalIPduRefConditional.Owner = ISignalIPduGroup
        ##############################################################################

        for ISignalIpduGroup in ISignalIpduGroupCollection:
        
            for referencedby in ISignalIpduGroup.ReferencedFromList:        
            #Delete SystemFibexElement ref
            ####################################################                                
                if type(referencedby) is VFibexElement_Ref:
                   SystemFibexElement = referencedby
                   SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference
        
                elif type(referencedby.Owner) is VPncMapping:                 
                     PncGroupRefCollection.add(referencedby)
                elif type(referencedby.Owner) is VEcuInstance:    
                     AssociatedComIPduGroupRefsCollection.add(referencedby)
    
    

            ISignalIpduGroup.Owner.RemoveElement(ISignalIpduGroup) 

        #remove the collected PncGroupRefs
        for PncGroupRef in PncGroupRefCollection:
            PncMapping = PncGroupRef.Owner
            PncMapping.RemovePncGroup(PncGroupRef)

            #remove the collected AssociatedComIPduGroupRefs
        for AssociatedComIpduGroupRef in AssociatedComIPduGroupRefsCollection:
            EcuInstance = AssociatedComIpduGroupRef.Owner                       
            EcuInstance.RemoveAssociatedComIPduGroup(AssociatedComIpduGroupRef)
                    
        ##############################################################################


      


        for PduTriggering in PduTriggeringCollection:
        
            #if PduTriggering is located in Cluster Ethernet?
            #there are no frames , but socketconnections
            if type(PduTriggering.Owner) is VEthernetPhysicalChannel:
                 deleteSocketConnectionIPduIdentifier(PduTriggering)



            #if PduTriggering is located in FlexRay/Lin/Can Cluster?
            #frames have to be deleted, access to pdutoframemappings to delete them
            elif isinstance(PduTriggering.Owner, IPhysicalChannel):
                 deleteFrameOfPdu(PduTriggering, ContainerIPduCollection,FrameTriggeringCollection, SourceTargetIPduMappingsCollection)




        #Delete Empty ContainerIPdus and empty Frames(without PduTriggerings)
        ########################################################################################################################################################
        #Delete IContainerIPdus
        if ContainerIPduCollection.Count >0:
            for collectedContainerIPdu in ContainerIPduCollection:
                if collectedContainerIPdu.ContainedPduTriggeringList.Count == 0:
    

                    #Collect and delete references
                    ####################################################            
                    for referencedby in collectedContainerIPdu.ReferencedFromList:
                    
                        #Collect PduToFrameMapping
                        if type(referencedby.Owner) is VPduToFrameMapping:
                           PduToFrameMappingCollection.add(referencedby.Owner)


                        #Delete SystemFibexElement ref
                        ####################################################                                
                        elif type(referencedby) is VFibexElement_Ref:
                           SystemFibexElement = referencedby
                           SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference


                        #Collect PduTriggering ref
                        ####################################################                                
                        elif type(referencedby.Owner) is VPduTriggering:
                           PduTriggeringCollection.add(referencedby.Owner)
                       



                    #Now Delete ContainerIPdu
                    ####################################################            
                    collectedContainerIPdu.Owner.RemoveElement(collectedContainerIPdu)
               

        ########################################################################################################################################################    
                
                
         #delete collected empty FrameTriggerings
        ########################################################################################################            
        if FrameTriggeringCollection.Count >0:
            for frameTriggering in FrameTriggeringCollection:
                if frameTriggering.PduTriggeringList.Count == 0:
                
                    #Collect Frame and FramePorts to delete 
                    if frameTriggering.FrameSpecified == True:
                       FrameCollection.add(frameTriggering.Frame)                
                       FramePortCollection.add(frameTriggering.FramePortList)
       

        #check if the frametriggerings are being referenced by LinScheduleTables
        ########################################################################################################            
        for frameTriggering in FrameTriggeringCollection:
            for referencedby in frameTriggering.ReferencedFromList:
            
                if type(referencedby.Owner) is VApplicationEntry:              
                   ApplicationEntriesCollection.add(referencedby.Owner)


        #now delete the collected applicationEntries

        for applicationEntry in ApplicationEntriesCollection:
            applicationEntry.FrameTriggeringSpecified = False


        ########################################################################################################            




            #delete collected Frames
        for frameRef in FrameCollection:
            if type(frameRef) is VFrame_Ref:

               FindFrame = model.Find(frameRef.Value)
               if not FindFrame is None:
                  if FindFrame.Count >0:
                     Frame = FindFrame[0]  
          
                     for referencedby in Frame.ReferencedFromList:
                   
                        #delete FibexElement
                        #########################################################
                            
                        if type(referencedby) is VFibexElement_Ref:
                           SystemFibexElement = referencedby
                           SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference
                        #########################################################

                  Frame.Owner.RemoveElement(Frame)
            elif isinstance(frameRef, IFrame):
              
                 for referencedby in frameRef.ReferencedFromList:
                   
                     #delete FibexElement
                     #########################################################
                            
                     if type(referencedby) is VFibexElement_Ref:
                        SystemFibexElement = referencedby
                        SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference
                     #########################################################

                 Frame.Owner.RemoveElement(frameRef)

    
        #delete FrameTriggerings
        for frameTriggering in FrameTriggeringCollection:
            PhysicalChannel =  frameTriggering.Owner
            PhysicalChannel.RemoveFrameTriggering(frameTriggering)
        ########################################################################################################            


        #Now delete the PduToFrameMappings 
        for pduToFrameMapping in PduToFrameMappingCollection:
            Frame = pduToFrameMapping.Owner
            Frame.RemovePduToFrameMapping(pduToFrameMapping)



        #Deleted affected IPduMappings(Gateway)
        for IPduMappingSourceOrTarget in SourceTargetIPduMappingsCollection:
            Gateway = IPduMappingSourceOrTarget.Owner
            Gateway.RemoveIPduMapping(IPduMappingSourceOrTarget)        

        #DO NOT DELETE PDUTRIGGERINGS UNTIL YOU HAVE DELETED THE ISIGNALIPDUS
        #Delete the collected PduTriggerings
        for pduTriggering in PduTriggeringCollection:
            PhysicalChannel = pduTriggering.Owner
            PhysicalChannel.RemovePduTriggering(pduTriggering)

    
        #Delete XcpPDUs
    
        if  XcpPduCollection.Count >2:
            logFile.write("\n deleted XcpPdus \n")
            logFile.write("################################################### \n")
            for xcpPdu in XcpPduCollection:
                if type(xcpPdu) is VXcpPdu:

                   logFile.write("{0}\n".format(xcpPdu.AsrPath))    
                   xcpPdu.Owner.RemoveElement(xcpPdu)
            logFile.write("################################################### \n")   
        else:
            logFile.write("\n deleted XcpPdus \n")
            logFile.write("################################################### \n")                
            logFile.write("the file does not contain XcpPdus\n")                
            logFile.write("################################################### \n")                


        return XcpPduCollection
    
    except Exception, e: 
        with open("{0}/error_log.txt".format(os.path.dirname(os.path.realpath(__file__))), "w") as f:
             f.write("{0}\error while deleting XcpPdus----------------------------------------------------\n") 
             f.write("{0}\n".format(e))


def DeleteNmPdus(NmPduCollection, logFile):
    
    try:
        ISignalToIPduMappingsCollection = set()
        PduToFrameMappingCollection = set()
        PduTriggeringCollection = set()
        ISignalIpduGroupCollection = set()    
        ISignalTriggeringCollection = set()
        ISignalPortCollection = set()
        FrameTriggeringCollection = set()
        ContainerIPduCollection = set()        
        FrameCollection = set()
        FramePortCollection = set()
        SourceTargetIPduMappingsCollection = set()
        SourceTargetISignalMappingsCollection = set()
        AssociatedComIPduGroupRefsCollection = set() #EcuInstance ISignalIPduGroups
        PncGroupRefCollection = set()  #SystemMapping --> ISignalIPduGroups
        TPConnectionsCollection = set()
        ApplicationEntriesCollection = set()
        J1939TpPgCollection = set()

        counter = 0
        for CollectedNmPdu in NmPduCollection:


            if type(CollectedNmPdu) is VNmPdu:
           

            
               #Collect ISignaltoIPduMappings to delete also ISignals later.
               ##############################################################################

               for ISignalToIPduMapping in CollectedNmPdu.ISignalToIPduMappingList:
                   ISignalToIPduMappingsCollection.add(ISignalToIPduMapping)

               ##############################################################################                        
            
               for referencedby in CollectedNmPdu.ReferencedFromList:
           
           
               #Collect referenced IPduToFrameMappings
               ##############################################################################               
               #If the ISignalIPdu is not being referenced by any IPduToFrameMapping the reason could be that :
               #a) the ISignalIPdu is being sent by a MultiplexedIPdu
               #b) the ISignalIPdu is being sent over an Ethernet Bus (Socket Connection)
               #c) the ISignalIPdu is packed in IContainerIPdus
               #d) the ISignalIPdu was wrongly modelled , because its not linked to any Frame           

                   if type(referencedby.Owner) is VPduToFrameMapping:
                      PduToFrameMappingCollection.add(referencedby.Owner)
                  
               ##############################################################################


               
               #Collect referenced IPduTriggerings
               ##############################################################################

                   elif type(referencedby.Owner) is VPduTriggering:
                      PduTriggeringCollection.add(referencedby.Owner)
                   
               ##############################################################################



               #Collect referenced ISignalIPduRefConditional ---> ISignalIPduRefConditional.Owner = ISignalIPduGroup
               ##############################################################################

                   elif type(referencedby.Owner) is VISignalIPduRefConditional:
                      ISignalIpduGroupCollection.add(referencedby.Owner.Owner)
                   
               ##############################################################################


               #Collect SystemRefs
               ##############################################################################

                   elif type(referencedby) is VFibexElement_Ref:
                        SystemFibexElement = referencedby.Owner
                        SystemFibexElement.FibexElementSpecified = False #Delete the reference
                   
               ##############################################################################




               #Collect TPConfigs (MultiplexedIPdus)
               ##############################################################################
           
                   elif isinstance(referencedby.Owner, ITpConnection):
                        TPConnectionsCollection.add(referencedby.Owner)
                   
               ##############################################################################

               #Collect
               ##############################################################################
           
                   elif type(referencedby.Owner) is VJ1939TpPg:
                        J1939TpPgCollection.add(referencedby.Owner.Owner)                      
               ##############################################################################           

    
    
        #Now iterate over the collected ISignalToIPduMappings and delete the referenced ISignals or ISignalGroups
        ########################################################################################################################################################################################################################################################################################################################

        for ISignalToIPduMapping in ISignalToIPduMappingsCollection:

            #ISignalRef Case
            ####################################################################################################################################################################################################################################
            if ISignalToIPduMapping.ISignalSpecified == True:
           
               #Find ISignal and delete it
               FindISignal = model.Find(ISignalToIPduMapping.ISignal.Value)
               if not FindISignal is None and FindISignal.Count >0:
                  
                  #Delete it!
                  ISignalToDelete = FindISignal[0]
               
               
                  #Before the ISignal is deleted the following referenced elements can be deleted
                  #(FibexElements) ----> of the ISignal in System
                  #ISignalTriggering ---> which is located in the Cluster ( Can, Ethernet, FlexRay, Ethernet)
                  #SystemSignal  (maybe)
                  ###########################################################################################################################################################################



                  for referencedby in ISignalToDelete.ReferencedFromList:
                   
                       #delete FibexElement
                       #########################################################
                   
                       if type(referencedby) is VFibexElement_Ref:
                          SystemFibexElement = referencedby
                          SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference
                       #########################################################

                   
                   
                       #delete ISignalTriggering and ISignalPort ( referenced ISignalTriggering in ISignal)
                       #########################################################
                       elif type(referencedby.Owner) is VISignalTriggering:
                          ISignalTriggering = referencedby.Owner
                      
                          #Add the ISignalTriggering to the Collection
                          ISignalTriggeringCollection.add(ISignalTriggering)

                          #find out whether an ISignalPort exists in the ISignalTriggering, if so , then delete it.
                          if ISignalTriggering.ISignalPortList.Count >0:                         
                             for ISignalPort in ISignalTriggering.ISignalPortList:
                                 FindISignalPort = model.Find(ISignalPort.Value)
                                 if not FindISignalPort is None:
                                    ISignalPortCollection.add(FindISignalPort[0])
                       #########################################################



                  #Finally Delete the ISignal
                  PackageFromISignal = ISignalToDelete.Parent
                  PackageFromISignal.RemoveElement(ISignalToDelete)              
            ####################################################################################################################################################################################################################################

       

            #ISignalGroupRef Case
            ####################################################################################################################################################################################################################################
            #if ISignalToIPduMapping
            if ISignalToIPduMapping.ISignalGroupSpecified == True:
           
               #Find ISignal and delete it
               FindISignalGroup = model.Find(ISignalToIPduMapping.ISignalGroup.Value)
               if not FindISignalGroup is None and FindISignalGroup.Count > 0:
                   #Delete it!
                  ISignalGroupToDelete = FindISignalGroup[0]

                  #Before the ISignalGroup is deleted the following referenced elements can be deleted
                  #(FibexElements) ----> of the ISignalGroup in System
                  #ISignalTriggering ---> which is located in the Cluster ( Can, Ethernet, FlexRay, Ethernet)
                  #SystemSignalGroup  (maybe)
                  ################################################################################################################
              
              
                  for referencedby in ISignalGroupToDelete.ReferencedFromList:
                   
                       #delete FibexElement
                       #########################################################
                   
                       if type(referencedby) is VFibexElement_Ref:
                          SystemFibexElement = referencedby
                          SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference
                       #########################################################

                   
                   
                       #delete ISignalTriggering and ISignalPort ( referenced ISignalTriggering in ISignalGroup)
                       #########################################################
                       elif type(referencedby.Owner) is VISignalTriggering:
                          ISignalTriggering = referencedby.Owner

                          #Add the ISignalTriggering to the Collection
                          ISignalTriggeringCollection.add(ISignalTriggering)
                      
                          #find out whether an ISignalPort exists in the ISignalTriggering, if so , then delete it.
                          if ISignalTriggering.ISignalPortList.Count >0:
                             for ISignalPort in ISignalTriggering.ISignalPortList:
                                 FindISignalPort = model.Find(ISignalPort.Value)
                                 if not FindISignalPort is None:
                                    ISignalPortCollection.add(FindISignalPort[0])
                       #########################################################



                  #Finally Delete the ISignalGroup
                  PackageFromISignalGroup = ISignalGroupToDelete.Parent
                  PackageFromISignalGroup.RemoveElement(ISignalGroupToDelete)
            ################################################################################################################

        
            #DeleteISignalToPduMapping
    
            ISignalToIPduMapping.Owner.RemoveISignalToIPduMapping(ISignalToIPduMapping)
            ####################################################################################################################################################################################################################################

        #Now Delete the collected information:

        ##############################################################################
    
    
        #Delete the collected TPConnections

        ##############################################################################           
        for TPConnection in TPConnectionsCollection:
            TPConnection.Owner.RemoveTpConnection(TPConnection)
        
        ##############################################################################

    
        #Delete the collected J1939 TPConnections

        ##############################################################################           
        for J1939TPConnection in J1939TpPgCollection:
            if hasattr(J1939TPConnection.Owner, "RemoveTpConnection"):
               J1939TPConnection.Owner.RemoveTpConnection(J1939TPConnection)
        
        ##############################################################################


    
    
        #Delete the collected ISignalTriggerings
        for ISignalTriggering in ISignalTriggeringCollection:
        
            #Collect ISignalMappings before deleting the collected ISignalTriggerings
            ##############################################################################
            for referencedby in ISignalTriggering.ReferencedFromList:
                if type(referencedby.Owner) is VISignalMapping:
                   SourceTargetISignalMappingsCollection.add(referencedby.Owner)
            ##############################################################################

            ISignalTriggering.Owner.RemoveISignalTriggering(ISignalTriggering)
        ##############################################################################


        #delete collected ISignalMappings
        for ISignalMapping in SourceTargetISignalMappingsCollection:
            Gateway = ISignalMapping.Owner
            Gateway.RemoveSignalMapping(ISignalMapping)


        ##############################################################################
        #Delete the collected ISignalPorts
        for ISignalPort in ISignalPortCollection:
            ISignalPort.Owner.RemoveEcuCommPortInstance(ISignalPort)
        ##############################################################################
           


        #Delete the collected ISignalIPduRefConditional ---> ISignalIPduRefConditional.Owner = ISignalIPduGroup
        ##############################################################################

        for ISignalIpduGroup in ISignalIpduGroupCollection:
        
            for referencedby in ISignalIpduGroup.ReferencedFromList:        
            #Delete SystemFibexElement ref
            ####################################################                                
                if type(referencedby) is VFibexElement_Ref:
                   SystemFibexElement = referencedby
                   SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference
        
                elif type(referencedby.Owner) is VPncMapping:                 
                     PncGroupRefCollection.add(referencedby)
                elif type(referencedby.Owner) is VEcuInstance:    
                     AssociatedComIPduGroupRefsCollection.add(referencedby)
    
    

            ISignalIpduGroup.Owner.RemoveElement(ISignalIpduGroup) 

        #remove the collected PncGroupRefs
        for PncGroupRef in PncGroupRefCollection:
            PncMapping = PncGroupRef.Owner
            PncMapping.RemovePncGroup(PncGroupRef)

            #remove the collected AssociatedComIPduGroupRefs
        for AssociatedComIpduGroupRef in AssociatedComIPduGroupRefsCollection:
            EcuInstance = AssociatedComIpduGroupRef.Owner                       
            EcuInstance.RemoveAssociatedComIPduGroup(AssociatedComIpduGroupRef)
                    
        ##############################################################################


      


        for PduTriggering in PduTriggeringCollection:
        
            #if PduTriggering is located in Cluster Ethernet?
            #there are no frames , but socketconnections
            if type(PduTriggering.Owner) is VEthernetPhysicalChannel:
                 deleteSocketConnectionIPduIdentifier(PduTriggering)



            #if PduTriggering is located in FlexRay/Lin/Can Cluster?
            #frames have to be deleted, access to pdutoframemappings to delete them
            elif isinstance(PduTriggering.Owner, IPhysicalChannel):
                 deleteFrameOfPdu(PduTriggering, ContainerIPduCollection,FrameTriggeringCollection, SourceTargetIPduMappingsCollection)




        #Delete Empty ContainerIPdus and empty Frames(without PduTriggerings)
        ########################################################################################################################################################
        #Delete IContainerIPdus
        if ContainerIPduCollection.Count >0:
            for collectedContainerIPdu in ContainerIPduCollection:
                if collectedContainerIPdu.ContainedPduTriggeringList.Count == 0:
    

                    #Collect and delete references
                    ####################################################            
                    for referencedby in collectedContainerIPdu.ReferencedFromList:
                    
                        #Collect PduToFrameMapping
                        if type(referencedby.Owner) is VPduToFrameMapping:
                           PduToFrameMappingCollection.add(referencedby.Owner)


                        #Delete SystemFibexElement ref
                        ####################################################                                
                        elif type(referencedby) is VFibexElement_Ref:
                           SystemFibexElement = referencedby
                           SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference


                        #Collect PduTriggering ref
                        ####################################################                                
                        elif type(referencedby.Owner) is VPduTriggering:
                           PduTriggeringCollection.add(referencedby.Owner)
                       



                    #Now Delete ContainerIPdu
                    ####################################################            
                    collectedContainerIPdu.Owner.RemoveElement(collectedContainerIPdu)
               

        ########################################################################################################################################################    
                
                
         #delete collected empty FrameTriggerings
        ########################################################################################################            
        if FrameTriggeringCollection.Count >0:
            for frameTriggering in FrameTriggeringCollection:
                if frameTriggering.PduTriggeringList.Count == 0:
                
                    #Collect Frame and FramePorts to delete 
                    if frameTriggering.FrameSpecified == True:
                       FrameCollection.add(frameTriggering.Frame)                
                       FramePortCollection.add(frameTriggering.FramePortList)
       

        #check if the frametriggerings are being referenced by LinScheduleTables
        ########################################################################################################            
        for frameTriggering in FrameTriggeringCollection:
            for referencedby in frameTriggering.ReferencedFromList:
            
                if type(referencedby.Owner) is VApplicationEntry:              
                   ApplicationEntriesCollection.add(referencedby.Owner)


        #now delete the collected applicationEntries

        for applicationEntry in ApplicationEntriesCollection:
            applicationEntry.FrameTriggeringSpecified = False


        ########################################################################################################            




            #delete collected Frames
        for frameRef in FrameCollection:
            if type(frameRef) is VFrame_Ref:

               FindFrame = model.Find(frameRef.Value)
               if not FindFrame is None:
                  if FindFrame.Count >0:
                     Frame = FindFrame[0]  
          
                     for referencedby in Frame.ReferencedFromList:
                   
                        #delete FibexElement
                        #########################################################
                            
                        if type(referencedby) is VFibexElement_Ref:
                           SystemFibexElement = referencedby
                           SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference
                        #########################################################

                  Frame.Owner.RemoveElement(Frame)
            elif isinstance(frameRef, IFrame):
              
                 for referencedby in frameRef.ReferencedFromList:
                   
                     #delete FibexElement
                     #########################################################
                            
                     if type(referencedby) is VFibexElement_Ref:
                        SystemFibexElement = referencedby
                        SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference
                     #########################################################

                 Frame.Owner.RemoveElement(frameRef)

    
        #delete FrameTriggerings
        for frameTriggering in FrameTriggeringCollection:
            PhysicalChannel =  frameTriggering.Owner
            PhysicalChannel.RemoveFrameTriggering(frameTriggering)
        ########################################################################################################            


        #Now delete the PduToFrameMappings 
        for pduToFrameMapping in PduToFrameMappingCollection:
            Frame = pduToFrameMapping.Owner
            Frame.RemovePduToFrameMapping(pduToFrameMapping)



        #Deleted affected IPduMappings(Gateway)
        for IPduMappingSourceOrTarget in SourceTargetIPduMappingsCollection:
            Gateway = IPduMappingSourceOrTarget.Owner
            Gateway.RemoveIPduMapping(IPduMappingSourceOrTarget)        

        #DO NOT DELETE PDUTRIGGERINGS UNTIL YOU HAVE DELETED THE ISIGNALIPDUS
        #Delete the collected PduTriggerings
        for pduTriggering in PduTriggeringCollection:
            PhysicalChannel = pduTriggering.Owner
            PhysicalChannel.RemovePduTriggering(pduTriggering)

    
        #Delete NmPDUs
    
        if  NmPduCollection.Count >2:
            logFile.write("\n deleted NmPdus \n")
            logFile.write("################################################### \n")
            for nmPdu in NmPduCollection:
                if type(nmPdu) is VNmPdu:

                   logFile.write("{0}\n".format(nmPdu.AsrPath))    
                   nmPdu.Owner.RemoveElement(nmPdu)
            logFile.write("################################################### \n")   
        else:
            logFile.write("\n deleted NmPdus \n")
            logFile.write("################################################### \n")                
            logFile.write("the file does not contain NmPdus\n")                
            logFile.write("################################################### \n")                


        return NmPduCollection
    
    except Exception, e: 
        with open("{0}/error_log.txt".format(os.path.dirname(os.path.realpath(__file__))), "w") as f:
             f.write("{0}\error while deleting NmPdus----------------------------------------------------\n") 
             f.write("{0}\n".format(e))


def DeleteSecuredIPdus(SecuredIPduCollection, logFile):
    try: 
        
        PduToFrameMappingCollection = set()
        GlobalTimeDomainCollection = set()
        PduTriggeringCollection = set()
        ContainerIPduCollection = set()
        FrameTriggeringCollection = set()
        SourceTargetIPduMappingsCollection = set()
        FrameCollection = set()
        FramePortCollection = set()                    
        ApplicationEntriesCollection = set()

    
        #Delete the found GeneralPurposePdus which are not from the category DoIP
        ##############################################################################################
        for SecuredIPdu in SecuredIPduCollection:
                
            if type(SecuredIPdu) is VSecuredIPdu:
                for referencedby in SecuredIPdu.ReferencedFromList:

               
                    #Collect referenced PduToFrameMappings
                    ##############################################################################                     

                     if type(referencedby.Owner) is VPduToFrameMapping:
                        PduToFrameMappingCollection.add(referencedby.Owner)
                  
                    ##############################################################################

                    #delete reference FibexElement in System
                    ##############################################################################                     

                     elif type(referencedby) is VFibexElement_Ref:
                         SystemFibexElement = referencedby.Owner
                         SystemFibexElement.FibexElementSpecified = False #Delete the reference
                  
                    ##############################################################################
           
           
                    #Collect referenced IPduTriggerings
                    ##############################################################################

                     elif type(referencedby.Owner) is VPduTriggering:
                          PduTriggeringCollection.add(referencedby.Owner)
                   
                    ##############################################################################
    

        ################################################################################################

        for PduTriggering in PduTriggeringCollection:
        
        #if PduTriggering is located in Cluster Ethernet?
        #there are no frames , but socketconnections
            if type(PduTriggering.Owner) is VEthernetPhysicalChannel:
               deleteSocketConnectionIPduIdentifier(PduTriggering)



        #if PduTriggering is located in FlexRay/Lin/Can Cluster?
        #frames have to be deleted, access to pdutoframemappings to delete them
            elif isinstance(PduTriggering.Owner, IPhysicalChannel):
                 deleteFrameOfPdu(PduTriggering, ContainerIPduCollection,FrameTriggeringCollection, SourceTargetIPduMappingsCollection)
             

        ##############################################################################################

          #delete collected empty FrameTriggerings
        ########################################################################################################            
        if FrameTriggeringCollection.Count >0:
            for frameTriggering in FrameTriggeringCollection:
                if frameTriggering.PduTriggeringList.Count == 0:
                
                    #Collect Frame and FramePorts to delete 
                    if frameTriggering.FrameSpecified == True:
                       FrameCollection.add(frameTriggering.Frame)                
                       if not frameTriggering.FramePortList is None:
                          FramePortCollection.add(frameTriggering.FramePortList)

    


        #check if the frametriggerings are being referenced by LinScheduleTables
        ########################################################################################################            
        for frameTriggering in FrameTriggeringCollection:
            for referencedby in frameTriggering.ReferencedFromList:
            
                if type(referencedby.Owner) is VApplicationEntry:              
                   ApplicationEntriesCollection.add(referencedby.Owner)


        #now delete the collected applicationEntries

        for applicationEntry in ApplicationEntriesCollection:
            applicationEntry.FrameTriggeringSpecified = False


        ########################################################################################################   

    
        #delete FrameTriggerings
        for frameTriggering in FrameTriggeringCollection:
            PhysicalChannel =  frameTriggering.Owner
            PhysicalChannel.RemoveFrameTriggering(frameTriggering)
        ##############################################################################################   


        #Now delete the PduToFrameMappings 
        for pduToFrameMapping in PduToFrameMappingCollection:
            Frame = pduToFrameMapping.Owner
            FrameCollection.add(Frame)
            Frame.RemovePduToFrameMapping(pduToFrameMapping)
        
    
        ##############################################################################################
            #delete collected Frames
        for frameRef in FrameCollection:
            if type(frameRef) is VFrame_Ref:

               FindFrame = model.Find(frameRef.Value)
               if not FindFrame is None:
                  if FindFrame.Count >0:
                     Frame = FindFrame[0]  
          
                     for referencedby in Frame.ReferencedFromList:
                   
                        #delete FibexElement
                        #########################################################
                            
                        if type(referencedby) is VFibexElement_Ref:
                           SystemFibexElement = referencedby
                           SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference
                        #########################################################

                  Frame.Owner.RemoveElement(Frame)
            elif isinstance(frameRef, IFrame):
              
                 for referencedby in frameRef.ReferencedFromList:
                   
                     #delete FibexElement
                     #########################################################
                            
                     if type(referencedby) is VFibexElement_Ref:
                        SystemFibexElement = referencedby
                        SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference
                     #########################################################

                 Frame.Owner.RemoveElement(frameRef)

        #Deleted affected IPduMappings(Gateway) if there were collected
        for IPduMappingSourceOrTarget in SourceTargetIPduMappingsCollection:
            Gateway = IPduMappingSourceOrTarget.Owner
            Gateway.RemoveIPduMapping(IPduMappingSourceOrTarget)        
    

        #Delete Empty ContainerIPdus and empty Frames(without PduTriggerings)
        ########################################################################################################################################################
        #Delete IContainerIPdus
        if ContainerIPduCollection.Count >0:
            for collectedContainerIPdu in ContainerIPduCollection:
                if collectedContainerIPdu.ContainedPduTriggeringList.Count == 0:
    

                    #Collect and delete references
                    ####################################################            
                    for referencedby in collectedContainerIPdu.ReferencedFromList:
                    
                        #Collect PduToFrameMapping
                        if type(referencedby.Owner) is VPduToFrameMapping:
                           PduToFrameMappingCollection.add(referencedby.Owner)


                        #Delete SystemFibexElement ref
                        ####################################################                                
                        elif type(referencedby) is VFibexElement_Ref:
                           SystemFibexElement = referencedby
                           SystemFibexElement.Owner.FibexElementSpecified = False #Delete the reference


                        #Collect PduTriggering ref
                        ####################################################                                
                        elif type(referencedby.Owner) is VPduTriggering:
                           PduTriggeringCollection.add(referencedby.Owner)
                       



                    #Now Delete ContainerIPdu
                    ####################################################            
                    collectedContainerIPdu.Owner.RemoveElement(collectedContainerIPdu)

        #DO NOT DELETE PDUTRIGGERINGS UNTIL YOU HAVE DELETED THE ISIGNALIPDUS
        #Delete the collected PduTriggerings
        for pduTriggering in PduTriggeringCollection:
            PhysicalChannel = pduTriggering.Owner
            PhysicalChannel.RemovePduTriggering(pduTriggering)

    
        #Delete the GeneralPurposePdus
        ########################################################################################
        if SecuredIPduCollection.Count >2:
            logFile.write("\n deleted SecuredIPdus \n")
            logFile.write("################################################### \n")
            for SecuredIPdu in SecuredIPduCollection:
                if type(SecuredIPdu) is VSecuredIPdu:

                   logFile.write("{0}\n  ".format(SecuredIPdu.AsrPath))    
                   SecuredIPdu.Owner.RemoveElement(SecuredIPdu)
            logFile.write("################################################### \n")
        else:
            logFile.write("\n deleted SecuredIPdus \n")
            logFile.write("################################################### \n")
            logFile.write("the file does not contain SecuredIPdus \n")
            logFile.write("################################################### \n")
        return SecuredIPduCollection
    except Exception, e: 
           with open("{0}/error_log.txt".format(os.path.dirname(os.path.realpath(__file__))), "w") as f:
                f.write("{0}\error while deleting SecuredIPdus----------------------------------------------------\n") 
                f.write("{0}\n".format(e))

def Execute():

    try:
        Arpackage = model        
        ListPdusToDelete = CreateListPdusToFind()
        ReadSpecificationXmlFile(ListPdusToDelete)
        ReadArxml(Arpackage, ListPdusToDelete)
        FilenameDeletedPdus = "{0}/" + "DeletedPdus.txt"

        logFile = open(FilenameDeletedPdus.format(os.path.dirname(os.path.realpath(__file__))), "w")
        
        logFile.write("\n Attention , the following Pdus and dependencies wont be deleted from the file: \n")
        logFile.write("################################################### \n")
        logFile.write("\n DcmIpdus with CanTpConnections \n")
        logFile.write("\n NmPdus \n")
        logFile.write("\n NPdus \n")        
        logFile.write("\n General purpose Pdus -->Category DoIP \n")
        logFile.write("################################################### \n")

        DeletePdus(ListPdusToDelete, logFile)
        print "done"
    except Exception, e: 
        with open("{0}/error_log.txt".format(os.path.dirname(os.path.realpath(__file__))), "w") as f:
             f.write("{0}\error log file ----------------------------------------------------\n") 
             f.write("{0}\n".format(e))

Execute()

                                    
