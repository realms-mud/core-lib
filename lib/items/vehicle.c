//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/item.c";

private object vehicleService;
private int currentStructure = -1;
object display = getService("configuration");

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    vehicleService = getService("vehicle");
    if (!objectp(vehicleService))
    {
        raise_error("vehicle.c: Could not load vehicleService.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getBlueprint()
{
    mapping result = ([]);
    string type = query("vehicle type");
    if (stringp(type) && objectp(vehicleService))
    {
        result = vehicleService->queryVehicleBlueprint(type);
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getComponent(string slot)
{
    mapping result = ([]);
    mapping components = query("components");
    if (mappingp(components) && member(components, slot))
    {
        string name = components[slot];
        if (stringp(name) && objectp(vehicleService))
        {
            result = vehicleService->queryComponent(name);
        }
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getAllComponentsWithDetails()
{
    mapping result = ([]);
    mapping components = query("components");
    if (mappingp(components) && objectp(vehicleService))
    {
        string *slots = m_indices(components);
        foreach(string slot in slots)
        {
            string name = components[slot];
            if (stringp(name))
            {
                result[slot] = vehicleService->queryComponent(name);
            }
            else
            {
                result[slot] = ([]);
            }
        }
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getComponents()
{
    mapping result = ([]);
    mapping components = query("components");
    if (mappingp(components))
    {
        result = components + ([]);
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getLocation()
{
    string result = "";
    string location = query("location");
    if (stringp(location))
    {
        result = location;
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setLocation(string newLocation)
{
    if (stringp(newLocation))
    {
        set("location", newLocation);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getCargo()
{
    mapping result = ([]);
    mapping cargo = query("cargo");
    if (mappingp(cargo))
    {
        result = cargo + ([]);
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getCargoQuantity(string item)
{
    int quantity = 0;
    mapping cargo = query("cargo") || ([]);
    if (item && stringp(item) && member(cargo, item))
    {
        quantity = cargo[item];
    }
    return quantity;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getCrew()
{
    mapping result = ([]);
    mapping crew = query("crew");
    if (mappingp(crew))
    {
        result = crew + ([]);
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getCrewAssignments()
{
    mapping result = ([]);
    mapping crew = getCrew();
    mapping blueprint = getBlueprint();
    
    if (mappingp(blueprint) && member(blueprint, "slots"))
    {
        mapping slots = blueprint["slots"];
        foreach (string slot in m_indices(slots))
        {
            if (slots[slot] == "henchman")
            {
                string assignment = member(crew, slot) ? crew[slot] : "unassigned";
                result[slot] = assignment;
            }
        }
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *getAvailableCrewSlots()
{
    string *result = ({});
    mapping blueprint = getBlueprint();
    
    if (mappingp(blueprint) && member(blueprint, "slots"))
    {
        mapping slots = blueprint["slots"];
        foreach (string slot in m_indices(slots))
        {
            if (slots[slot] == "henchman")
            {
                result += ({ slot });
            }
        }
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getCrewEfficiency()
{
    int efficiency = 50; // Base efficiency without crew
    mapping crew = getCrew();
    string *crewSlots = getAvailableCrewSlots();
    
    if (sizeof(crewSlots))
    {
        int filledSlots = 0;
        foreach (string slot in crewSlots)
        {
            if (member(crew, slot) && stringp(crew[slot]))
            {
                filledSlots++;
                // Add henchman skill bonuses here if available
                efficiency += 10; // Base bonus per crew member
            }
        }
        
        // Bonus for full crew
        if (filledSlots == sizeof(crewSlots))
        {
            efficiency += 15;
        }
    }
    
    int result = efficiency > 100 ? 100 : efficiency;
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getMaxStructure()
{
    int structure = 0;
    mapping blueprint = getBlueprint();
    if (mappingp(blueprint) && member(blueprint, "structure"))
    {
        structure = blueprint["structure"];
    }
    mapping components = query("components");
    if (mappingp(components))
    {
        foreach(string slot in m_indices(components))
        {
            mapping comp = getComponent(slot);
            if (mappingp(comp) && member(comp, "structure"))
            {
                structure += comp["structure"];
            }
        }
    }
    return structure;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getCurrentStructure()
{
    if (currentStructure < 0)
    {
        currentStructure = getMaxStructure();
    }
    return currentStructure;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getCapacity()
{
    int base = 0;
    mapping blueprint = getBlueprint();
    if (mappingp(blueprint) && member(blueprint, "capacity"))
    {
        base = blueprint["capacity"];
    }
    mapping components = query("components");
    if (mappingp(components))
    {
        foreach(string slot in m_indices(components))
        {
            mapping comp = getComponent(slot);
            if (mappingp(comp) && member(comp, "capacity bonus"))
            {
                base += comp["capacity bonus"];
            }
        }
    }
    
    // Apply crew efficiency to cargo capacity
    int efficiency = getCrewEfficiency();
    int result = (base * efficiency) / 100;
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getUsedSpace()
{
    int used = 0;
    mapping cargo = query("cargo");
    if (mappingp(cargo))
    {
        foreach(string item in m_indices(cargo))
        {
            used += cargo[item];
        }
    }
    return used;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getFreeSpace()
{
    int result = getCapacity() - getUsedSpace();
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getTradeProtection()
{
    int prot = 0;
    mapping blueprint = getBlueprint();
    if (mappingp(blueprint) && member(blueprint, "protection"))
    {
        prot = blueprint["protection"];
    }
    mapping components = query("components");
    if (mappingp(components))
    {
        foreach(string slot in m_indices(components))
        {
            mapping comp = getComponent(slot);
            if (mappingp(comp) && member(comp, "protection"))
            {
                prot += comp["protection"];
            }
        }
    }
    
    // Apply crew efficiency to protection
    int efficiency = getCrewEfficiency();
    int result = (prot * efficiency) / 100;
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getWeaponPower()
{
    int power = 0;
    mapping components = query("components");
    if (mappingp(components))
    {
        foreach(string slot in m_indices(components))
        {
            mapping comp = getComponent(slot);
            if (mappingp(comp) && member(comp, "class") && comp["class"] == "weapon")
            {
                int weaponPower = comp["attack power"] || comp["weight"] || 0;
                power += weaponPower;
            }
        }
    }
    
    // Apply crew efficiency to weapon power
    int efficiency = getCrewEfficiency();
    int result = (power * efficiency) / 100;
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getDefense()
{
    int defense = getTradeProtection();
    mapping components = query("components");
    if (mappingp(components))
    {
        foreach(string slot in m_indices(components))
        {
            mapping comp = getComponent(slot);
            if (mappingp(comp) && member(comp, "class") && comp["class"] == "defense")
            {
                int defenseBonus = comp["defense bonus"] || comp["protection"] || 0;
                defense += defenseBonus;
            }
        }
    }
    return defense;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getSpeed()
{
    int speed = 0;
    mapping blueprint = getBlueprint();
    if (mappingp(blueprint) && member(blueprint, "base speed"))
    {
        speed = blueprint["base speed"];
    }
    mapping components = query("components");
    if (mappingp(components))
    {
        foreach(string slot in m_indices(components))
        {
            mapping comp = getComponent(slot);
            if (mappingp(comp) && member(comp, "speed bonus"))
            {
                speed += comp["speed bonus"];
            }
        }
    }
    
    // Apply crew efficiency to speed
    int efficiency = getCrewEfficiency();
    int result = (speed * efficiency) / 100;
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getCrewRequirement()
{
    int required = 0;
    mapping blueprint = getBlueprint();
    if (mappingp(blueprint) && member(blueprint, "crew required"))
    {
        required = blueprint["crew required"];
    }
    return required;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int installComponent(string slot, string componentName)
{
    int result = 0;
    mapping components = query("components") || ([]);
    mapping blueprint = getBlueprint();
    
    if (objectp(vehicleService) && vehicleService->queryComponent(componentName))
    {
        // Check if slot exists and is valid for this vehicle
        if (mappingp(blueprint) && member(blueprint, "slots") && 
            member(blueprint["slots"], slot))
        {
            mapping component = vehicleService->queryComponent(componentName);
            string slotType = blueprint["slots"][slot];
            
            // Verify component matches slot type
            if (member(component, "class") && component["class"] == slotType)
            {
                components[slot] = componentName;
                set("components", components);
                result = 1;
            }
        }
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int removeComponent(string slot)
{
    int result = 0;
    mapping components = query("components") || ([]);
    mapping blueprint = getBlueprint();
    
    if (member(components, slot))
    {
        // Reset to unbuilt version
        if (mappingp(blueprint) && member(blueprint, "slots") && 
            member(blueprint["slots"], slot))
        {
            string slotType = blueprint["slots"][slot];
            components[slot] = sprintf("unbuilt %s", slotType);
            set("components", components);
            result = 1;
        }
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int addCargo(string item, int quantity)
{
    int result = 0;
    if (item && stringp(item) && quantity > 0 && getFreeSpace() >= quantity)
    {
        mapping cargo = query("cargo") || ([]);
        if (!member(cargo, item))
        {
            cargo[item] = 0;
        }
        cargo[item] += quantity;
        set("cargo", cargo);
        result = 1;
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int removeCargo(string item, int quantity)
{
    int result = 0;
    mapping cargo = query("cargo") || ([]);
    if (item && stringp(item) && quantity > 0 && member(cargo, item) && cargo[item] >= quantity)
    {
        cargo[item] -= quantity;
        if (cargo[item] <= 0)
        {
            m_delete(cargo, item);
        }
        set("cargo", cargo);
        result = 1;
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void assignCrew(string slot, string henchmanId)
{
    mapping crew = query("crew") || ([]);
    string *availableSlots = getAvailableCrewSlots();
    
    if (slot && stringp(henchmanId) && member(availableSlots, slot))
    {
        crew[slot] = henchmanId;
        set("crew", crew);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void assignCrewObject(string slot, object person)
{
    // Legacy method - convert to henchman ID system
    if (slot && objectp(person) && function_exists("query", person))
    {
        string henchmanId = person->query("henchman id") || 
                           person->query("name") || 
                           sprintf("crew_%d", time());
        assignCrew(slot, henchmanId);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void removeCrew(string slot)
{
    mapping crew = query("crew") || ([]);
    if (slot && member(crew, slot))
    {
        m_delete(crew, slot);
        set("crew", crew);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void unassignHenchman(string slot)
{
    removeCrew(slot);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void assignHenchman(string slot, string henchmanId)
{
    assignCrew(slot, henchmanId);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int takeDamage(int amount)
{
    int actual = amount > 0 ? amount : 0;
    int max = getMaxStructure();
    if (currentStructure < 0)
    {
        currentStructure = max;
    }
    currentStructure -= actual;
    if (currentStructure < 0)
    {
        currentStructure = 0;
    }
    return actual;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int repair(int amount)
{
    int max = getMaxStructure();
    int actual = amount > 0 ? amount : 0;
    if (currentStructure < 0)
    {
        currentStructure = max;
    }
    currentStructure += actual;
    if (currentStructure > max)
    {
        currentStructure = max;
    }
    return actual;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isDestroyed()
{
    int result = getCurrentStructure() <= 0;
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int attackVehicle(object target)
{
    int result = 0;
    if (objectp(target) && function_exists("takeDamage", target))
    {
        int attackPower = getWeaponPower();
        int defense = target->getDefense();
        int damageDealt = attackPower - defense;
        if (damageDealt < 1)
        {
            damageDealt = 1;
        }
        result = target->takeDamage(damageDealt);
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string displayVehicle(object player)
{
    string result = "Vehicle display not available.";
    if (objectp(vehicleService))
    {
        result = vehicleService->visualizeVehicle(player, this_object());
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
private string getStructureDetails(string colorConfig)
{
    int currentStr = getCurrentStructure();
    int maxStr = getMaxStructure();
    string structureColor = "data";
    if (currentStr < (maxStr / 4))
    {
        structureColor = "failure";
    }
    else if (currentStr < (maxStr / 2))
    {
        structureColor = "warning";
    }

    return display->decorate("Structure: ", "field header", "vehicle", colorConfig) +
        display->decorate(sprintf("%d", currentStr), structureColor, "vehicle", colorConfig) +
        display->decorate("/", "data", "vehicle", colorConfig) +
        display->decorate(sprintf("%d", maxStr), "data", "vehicle", colorConfig) + "\n";
}

/////////////////////////////////////////////////////////////////////////////
private string getCapacityDetails(string colorConfig)
{
    int usedSpace = getUsedSpace();
    int totalCapacity = getCapacity();
    string capacityColor = "data";
    if (usedSpace >= totalCapacity)
    {
        capacityColor = "warning";
    }
    else if (usedSpace >= (totalCapacity * 3 / 4))
    {
        capacityColor = "note";
    }
    return display->decorate("Capacity: ", "field header", "vehicle", colorConfig) +
        display->decorate(sprintf("%d", usedSpace), capacityColor, "vehicle", colorConfig) +
        display->decorate("/", "data", "vehicle", colorConfig) +
        display->decorate(sprintf("%d units used", totalCapacity), "data", "vehicle", colorConfig) + "\n";
}

/////////////////////////////////////////////////////////////////////////////
private string getCrewDetails(string colorConfig)
{
    string result = "";
    mapping crewAssignments = getCrewAssignments();
    if (sizeof(crewAssignments))
    {
        result += "\n" + display->decorate("Crew Assignments:", "section header", "vehicle", colorConfig) + "\n";
        foreach (string slot in m_indices(crewAssignments))
        {
            string assignment = crewAssignments[slot];
            string assignmentColor = (assignment == "unassigned") ? "failure" : "success";
            string displayName = (assignment == "unassigned") ? "Empty" : assignment;
            
            result += display->decorate("  ", "data", "vehicle", colorConfig) +
                      display->decorate(sprintf("%s: ", capitalize(slot)), "field header", "vehicle", colorConfig) +
                      display->decorate(displayName, assignmentColor, "vehicle", colorConfig) + "\n";
        }
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
private string getCrewEfficiencyDetails(string colorConfig)
{
    int efficiency = getCrewEfficiency();
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
    
    return display->decorate("Crew Efficiency: ", "field header", "vehicle", colorConfig) +
           display->decorate(sprintf("%d%%", efficiency), efficiencyColor, "vehicle", colorConfig) + "\n";
}

/////////////////////////////////////////////////////////////////////////////
private string getCargoDetails(string colorConfig)
{
    string result = "";
    mapping cargo = getCargo();

    if (sizeof(cargo))
    {
        result += "\n" + display->decorate("Cargo:", "section header", "vehicle", colorConfig) + "\n";
        foreach (string item in m_indices(cargo))
        {
            result += display->decorate("  ", "data", "vehicle", colorConfig) +
                      display->decorate(sprintf("%s: ", item), "field header", "vehicle", colorConfig) +
                      display->decorate(sprintf("%d units", cargo[item]), "data", "vehicle", colorConfig) + "\n";
        }
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getVehicleStatus(object player)
{
    string result = "Configuration service not available.";
    string colorConfig = player ? player->colorConfiguration() : "none";
    
    if (display)
    {
        mapping blueprint = getBlueprint();
        string vehicleName = blueprint["display name"] || query("vehicle type") || "Unknown Vehicle";
        
        result = display->decorate(sprintf("=== %s Status ===", vehicleName), 
                                      "header", "vehicle", colorConfig) + "\n";
        
        result += display->decorate("Location: ", "field header", "vehicle", colorConfig) +
                  display->decorate(getLocation(), "data", "vehicle", colorConfig) + "\n";
        
        result += getStructureDetails(colorConfig);
		result += getCapacityDetails(colorConfig);
        
        // Speed
        result += display->decorate("Speed: ", "field header", "vehicle", colorConfig) +
                  display->decorate(sprintf("%d", getSpeed()), "data", "vehicle", colorConfig) + "\n";
        
        // Protection
        result += display->decorate("Protection: ", "field header", "vehicle", colorConfig) +
                  display->decorate(sprintf("%d", getTradeProtection()), "data", "vehicle", colorConfig) + "\n";
        
		result += getCrewEfficiencyDetails(colorConfig);
		result += getCrewDetails(colorConfig);
        result += getCargoDetails(colorConfig);
        
        // Vehicle layout display
        result += "\n" + displayVehicle(player);
    }
    
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void initializeVehicle(mapping blueprint)
{
    if (mappingp(blueprint))
    {
        // Set basic properties
        set("vehicle type", blueprint["type"] || "unknown");
        set("name", blueprint["display name"] || blueprint["type"]);
        set("short", blueprint["display name"] || blueprint["type"]);
        set("long", blueprint["default description"] || "A vehicle.");
        
        // Initialize components with unbuilt versions
        mapping components = ([]);
        if (member(blueprint, "slots"))
        {
            foreach (string slot in m_indices(blueprint["slots"]))
            {
                string slotType = blueprint["slots"][slot];
                components[slot] = sprintf("unbuilt %s", slotType);
            }
        }
        set("components", components);
        
        // Initialize empty cargo and crew
        set("cargo", ([]));
        set("crew", ([]));
        
        // Set structure to max
        currentStructure = getMaxStructure();
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int set(string element, mixed data)
{
    int result = 0;
    
    // Enforce required elements for vehicles
    switch (element)
    {
        case "vehicle type":
        {
            if (!data || !stringp(data) || !vehicleService->queryVehicleBlueprint(data))
            {
                raise_error("vehicle.c: Invalid or missing vehicle type.\n");
            }
            break;
        }
        case "location":
        {
            if (!data || !stringp(data))
            {
                raise_error("vehicle.c: Invalid or missing location.\n");
            }
            break;
        }
        case "components":
        {
            if (!mappingp(data))
            {
                raise_error("vehicle.c: Components must be a mapping.\n");
            }
            break;
        }
        case "cargo":
        case "crew":
        {
            if (!mappingp(data))
            {
                data = ([]);
            }
            break;
        }
        case "current structure":
        {
            if (!intp(data) || data < 0)
            {
                data = getMaxStructure();
            }
            currentStructure = data;
            break;
        }
    }
    result = item::set(element, data);
    return result;
}
