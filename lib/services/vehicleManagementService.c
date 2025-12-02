//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getVehicleMenu(object user, string location)
{
    mapping ret = ([]);
    
    if (objectp(user))
    {
        object *vehicles = user->getVehiclesAtLocation(location);
        int counter = 1;
        
        // Purchase new vehicles
        ret[to_string(counter++)] = ([
            "name": "Purchase New Vehicle",
            "type": "purchase",
            "description": "Browse and purchase new vehicles for your fleet.\n",
            "selector": "vehiclePurchase",
            "canShow": 1
        ]);
        
        // List existing vehicles and management options
        if (sizeof(vehicles))
        {
            ret[to_string(counter++)] = ([
                "name": "View Vehicle Fleet",
                "type": "view",
                "description": "Display detailed information about your vehicle fleet.\n",
                "canShow": 1
            ]);
            
            foreach (object vehicle in vehicles)
            {
                if (objectp(vehicle))
                {
                    string vehicleName = vehicle->query("name") || "Unknown Vehicle";
                    string vehicleType = vehicle->query("vehicle type") || "unknown";
                    
                    ret[to_string(counter++)] = ([
                        "name": sprintf("Manage %s", vehicleName),
                        "type": "manage",
                        "vehicle": vehicle,
                        "description": sprintf("Manage this %s - enhance components, assign crew, and configure settings.\n", vehicleType),
                        "canShow": 1
                    ]);
                }
            }
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getPurchaseMenu(object user, string location, string vehicleType)
{
    mapping ret = ([]);
    
    if (objectp(user))
    {
        string *availableTypes = getService("vehicle")->queryAllVehicleTypes();
        int counter = 1;
        
        foreach (string type in availableTypes)
        {
            mapping blueprint = getService("vehicle")->queryVehicleBlueprint(type);
            if (sizeof(blueprint))
            {
                // Check prerequisites
                int canPurchase = 1;
                if (member(blueprint, "prerequisites"))
                {
                    canPurchase = user->canMeetPrerequisites(blueprint["prerequisites"]);
                }
                
                string costDisplay = sprintf(" ($%d)", blueprint["cost"]);
                if (user->getMoney() < blueprint["cost"])
                {
                    costDisplay += " low $";
                }
                
                ret[to_string(counter++)] = ([
                    "name": blueprint["display name"] + costDisplay,
                    "type": "purchase",
                    "vehicle type": type,
                    "cost": blueprint["cost"],
                    "description": sprintf("%s\n\nCost: %d gold\nCapacity: %d units\nCrew Required: %d\nSpeed: %d\nStructure: %d\nProtection: %d\n",
                        blueprint["default description"],
                        blueprint["cost"],
                        blueprint["capacity"],
                        blueprint["crew required"], 
                        blueprint["base speed"],
                        blueprint["structure"],
                        blueprint["protection"]),
                    "canShow": canPurchase
                ]);
            }
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getEnhancementMenu(object user, object vehicle, string slotType)
{
    mapping ret = ([]);
    
    if (objectp(user) && objectp(vehicle))
    {
        string vehicleType = vehicle->query("vehicle type");
        mapping blueprint = getService("vehicle")->queryVehicleBlueprint(vehicleType);
        mapping slots = blueprint["slots"] || ([]);
        mapping currentComponents = vehicle->getComponents();
        
        int counter = 1;
        
        // Show current vehicle layout
        ret[to_string(counter++)] = ([
            "name": "View Vehicle Layout",
            "type": "view",
            "description": "Display the current vehicle configuration and component layout.\n",
            "canShow": 1
        ]);
        
        // List available component slots
        foreach (string slot in m_indices(slots))
        {
            string componentClass = slots[slot];
            string currentComponent = member(currentComponents, slot) ? 
                currentComponents[slot] : "empty";
                
            ret[to_string(counter++)] = ([
                "name": sprintf("Upgrade %s Slot (%s)", capitalize(slot), currentComponent),
                "type": "slot",
                "slot": slot,
                "class": componentClass,
                "description": sprintf("Upgrade or install components in the %s slot.\n", slot),
                "canShow": 1
            ]);
        }
        
        // If a specific slot type is selected, show available components
        if (slotType)
        {
            string *availableComponents = getService("vehicle")->queryComponentsByClass(slotType);
            foreach (string componentName in availableComponents)
            {
                mapping component = getService("vehicle")->queryComponent(componentName);
                if (sizeof(component))
                {
                    int canInstall = 1;
                    if (member(component, "prerequisites"))
                    {
                        canInstall = user->canMeetPrerequisites(component["prerequisites"]);
                    }
                    
                    int cost = component["cost"] || 0;
                    string costDisplay = cost ? sprintf(" ($%d)", cost) : "";
                    if (cost && user->getMoney() < cost)
                    {
                        costDisplay += " low $";
                    }
                    
                    ret[to_string(counter++)] = ([
                        "name": componentName + costDisplay,
                        "type": "install",
                        "component": componentName,
                        "slot": slotType,
                        "cost": cost,
                        "description": sprintf("%s\n\nCost: %d gold\n",
                            component["description"] || "No description available.",
                            cost),
                        "canShow": canInstall
                    ]);
                }
            }
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getCrewAssignmentMenu(object user, object vehicle, string location, string slotType)
{
    mapping ret = ([]);
    
    if (objectp(user) && objectp(vehicle))
    {
        string vehicleType = vehicle->query("vehicle type");
        mapping blueprint = getService("vehicle")->queryVehicleBlueprint(vehicleType);
        mapping slots = blueprint["slots"] || ([]);
        mapping currentCrew = vehicle->getCrew();
        
        int counter = 1;
        
        // Show current crew assignments
        ret[to_string(counter++)] = ([
            "name": "View Current Crew",
            "type": "view",
            "description": "Display current crew assignments and their effectiveness.\n",
            "canShow": 1
        ]);
        
        // List henchman slots
        foreach (string slot in m_indices(slots))
        {
            if (slots[slot] == "henchman")
            {
                string currentAssignment = member(currentCrew, slot) ? 
                    currentCrew[slot] : "unassigned";
                    
                ret[to_string(counter++)] = ([
                    "name": sprintf("Manage %s Position (%s)", capitalize(slot), currentAssignment),
                    "type": "crew_slot",
                    "slot": slot,
                    "description": sprintf("Assign or reassign crew to the %s position.\n", slot),
                    "canShow": 1
                ]);
            }
        }
        
        // If a specific slot is selected, show available henchmen
        if (slotType)
        {
            mapping *availableHenchmen = user->getHenchmenAtLocation(location);
            foreach (mapping henchman in availableHenchmen)
            {
                if (henchman["activity"] == "idle")
                {
                    ret[to_string(counter++)] = ([
                        "name": sprintf("Assign %s", henchman["name"]),
                        "type": "assign",
                        "henchman": henchman["id"],
                        "slot": slotType,
                        "description": sprintf("Assign %s to the %s position.\n", 
                            henchman["name"], slotType),
                        "canShow": 1
                    ]);
                }
            }
            
            // Option to hire new crew
            ret[to_string(counter++)] = ([
                "name": "Hire Sailor (1000 gold)",
                "type": "hire",
                "henchman type": "sailor",
                "cost": 1000,
                "description": "Hire a new sailor for your crew.\n",
                "canShow": (user->getMoney() >= 1000)
            ]);
            
            ret[to_string(counter++)] = ([
                "name": "Hire Marine (1500 gold)",
                "type": "hire", 
                "henchman type": "marine",
                "cost": 1500,
                "description": "Hire a marine to defend your vessel.\n",
                "canShow": (user->getMoney() >= 1500)
            ]);
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object createVehicle(string vehicleType, string location)
{
    object result = 0;
    mapping blueprint = getService("vehicle")->queryVehicleBlueprint(vehicleType);
    
    if (sizeof(blueprint))
    {
        object vehicle = clone_object("/lib/items/vehicle.c");
        vehicle->set("vehicle type", vehicleType);
        vehicle->setLocation(location);
        vehicle->initializeVehicle(blueprint);
        result = vehicle;
    }
    
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string displayVehicleFleet(object user, string location)
{
    string result = "No vehicles available.";
    string colorConfig = user ? user->colorConfiguration() : "none";
    object configDict = getService("configuration");
    
    if (configDict && objectp(user))
    {
        object *vehicles = user->getVehiclesAtLocation(location);
        
        if (sizeof(vehicles))
        {
            result = configDict->decorate("=== Vehicle Fleet ===", "header", "vehicle", colorConfig) + "\n";
            
            foreach (object vehicle in vehicles)
            {
                if (objectp(vehicle))
                {
                    string vehicleName = vehicle->query("name") || "Unknown Vehicle";
                    string vehicleType = vehicle->query("vehicle type") || "unknown";
                    int capacity = vehicle->getCapacity();
                    int usedSpace = vehicle->getUsedSpace();
                    int efficiency = vehicle->getCrewEfficiency();
                    
                    result += "\n" + configDict->decorate(vehicleName, "field header", "vehicle", colorConfig) +
                              configDict->decorate(sprintf(" (%s)", vehicleType), "data", "vehicle", colorConfig) + "\n";
                    
                    result += configDict->decorate("  Capacity: ", "field header", "vehicle", colorConfig) +
                              configDict->decorate(sprintf("%d/%d units", usedSpace, capacity), "data", "vehicle", colorConfig) + "\n";
                    
                    string efficiencyColor = "data";
                    if (efficiency < 60)
                    {
                        efficiencyColor = "failure";
                    }
                    else if (efficiency < 80)
                    {
                        efficiencyColor = "warning";
                    }
                    else if (efficiency >= 95)
                    {
                        efficiencyColor = "success";
                    }
                    
                    result += configDict->decorate("  Crew Efficiency: ", "field header", "vehicle", colorConfig) +
                              configDict->decorate(sprintf("%d%%", efficiency), efficiencyColor, "vehicle", colorConfig) + "\n";
                }
            }
        }
    }
    
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int purchaseVehicle(object user, string vehicleType, string location)
{
    int result = 0;
    
    if (objectp(user) && stringp(vehicleType) && stringp(location))
    {
        mapping blueprint = getService("vehicle")->queryVehicleBlueprint(vehicleType);
        
        if (sizeof(blueprint))
        {
            int cost = blueprint["cost"] || 0;
            int canAfford = (user->getMoney() >= cost);
            int hasPrerequisites = 1;
            
            if (member(blueprint, "prerequisites"))
            {
                hasPrerequisites = user->canMeetPrerequisites(blueprint["prerequisites"]);
            }
            
            if (canAfford && hasPrerequisites)
            {
                user->addMoney(-cost);
                object vehicle = createVehicle(vehicleType, location);
                if (objectp(vehicle))
                {
                    user->addVehicle(vehicle);
                    result = 1;
                }
            }
        }
    }
    
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int installVehicleComponent(object user, object vehicle, string slot, string componentName)
{
    int result = 0;
    
    if (objectp(user) && objectp(vehicle) && stringp(slot) && stringp(componentName))
    {
        mapping component = getService("vehicle")->queryComponent(componentName);
        
        if (sizeof(component))
        {
            int cost = component["cost"] || 0;
            int canAfford = (user->getMoney() >= cost);
            int hasPrerequisites = 1;
            
            if (member(component, "prerequisites"))
            {
                hasPrerequisites = user->canMeetPrerequisites(component["prerequisites"]);
            }
            
            if (canAfford && hasPrerequisites)
            {
                int installed = vehicle->installComponent(slot, componentName);
                if (installed)
                {
                    user->addMoney(-cost);
                    result = 1;
                }
            }
        }
    }
    
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int assignCrewMember(object user, object vehicle, string slot, string henchmanId, string location)
{
    int result = 0;
    
    if (objectp(user) && objectp(vehicle) && stringp(slot) && stringp(henchmanId))
    {
        mapping *henchmen = user->getHenchmenAtLocation(location);
        int validHenchman = 0;
        
        foreach (mapping henchman in henchmen)
        {
            if (henchman["id"] == henchmanId && henchman["activity"] == "idle")
            {
                validHenchman = 1;
                break;
            }
        }
        
        if (validHenchman)
        {
            string *availableSlots = vehicle->getAvailableCrewSlots();
            if (member(availableSlots, slot))
            {
                vehicle->assignHenchman(slot, henchmanId);
                user->setHenchmanActivity(henchmanId, "assigned to vehicle");
                result = 1;
            }
        }
    }
    
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int hireCrewMember(object user, string location, string crewType, int cost)
{
    int result = 0;
    
    if (objectp(user) && stringp(location) && stringp(crewType) && (user->getMoney() >= cost))
    {
        user->addMoney(-cost);
        mapping henchmanData = ([
            "type": crewType,
            "activity": "idle"
        ]);
        object newHenchman = user->addHenchman(location, henchmanData);
        if (objectp(newHenchman))
        {
            result = 1;
        }
    }
    
    return result;
}