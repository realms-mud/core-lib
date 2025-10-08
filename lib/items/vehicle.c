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
    int capacity = 0;
    mapping blueprint = getBlueprint();
    if (mappingp(blueprint) && member(blueprint, "capacity"))
    {
        capacity = blueprint["capacity"];
    }
    mapping components = query("components");
    if (mappingp(components))
    {
        foreach(string slot in m_indices(components))
        {
            mapping comp = getComponent(slot);
            if (mappingp(comp) && member(comp, "capacity bonus"))
            {
                capacity += comp["capacity bonus"];
            }
        }
    }
    return capacity;
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
    return prot;
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
    return speed;
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
    return power;
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
    if (objectp(vehicleService) && vehicleService->queryComponent(componentName))
    {
        components[slot] = componentName;
        set("components", components);
        result = 1;
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
        if (mappingp(blueprint) && member(blueprint, "slots") && 
            member(blueprint["slots"], slot))
        {
            string slotType = blueprint["slots"][slot];
            components[slot] = sprintf("unbuilt %s", slotType);
            set("components", components);
            result = 1;
        }
        else
        {
            m_delete(components, slot);
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
public nomask void assignCrew(string role, object person)
{
    mapping crew = query("crew") || ([]);
    if (role && objectp(person))
    {
        crew[role] = person;
        set("crew", crew);
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
public nomask void assignHenchman(string slot, string henchmanId)
{
    mapping crew = query("crew") || ([]);
    if (slot && stringp(henchmanId))
    {
        crew[slot] = henchmanId;
        set("crew", crew);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void unassignHenchman(string slot)
{
    removeCrew(slot);
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
        
        int currentStr = getCurrentStructure();
        int maxStr = getMaxStructure();
        result += display->decorate("Structure: ", "field header", "vehicle", colorConfig) +
                  display->decorate(sprintf("%d/%d", currentStr, maxStr), "data", "vehicle", colorConfig) + "\n";
        
        int usedSpace = getUsedSpace();
        int totalCapacity = getCapacity();
        result += display->decorate("Capacity: ", "field header", "vehicle", colorConfig) +
                  display->decorate(sprintf("%d/%d units used", usedSpace, totalCapacity), "data", "vehicle", colorConfig) + "\n";
        
        result += display->decorate("Speed: ", "field header", "vehicle", colorConfig) +
                  display->decorate(sprintf("%d", getSpeed()), "data", "vehicle", colorConfig) + "\n";
        
        result += display->decorate("Protection: ", "field header", "vehicle", colorConfig) +
                  display->decorate(sprintf("%d", getTradeProtection()), "data", "vehicle", colorConfig) + "\n";
        
        mapping cargo = getCargo();
        if (sizeof(cargo))
        {
            result += "\n" + display->decorate("Cargo:", "section header", "vehicle", colorConfig) + "\n";
            foreach (string item in m_indices(cargo))
            {
                result += display->decorate(sprintf("  %s: %d units", item, cargo[item]), "data", "vehicle", colorConfig) + "\n";
            }
        }
        
        result += "\n" + displayVehicle(player);
    }
    
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void initializeVehicle(mapping blueprint)
{
    if (mappingp(blueprint))
    {
        set("vehicle type", blueprint["type"] || "unknown");
        set("name", blueprint["display name"] || blueprint["type"]);
        set("short", blueprint["display name"] || blueprint["type"]);
        set("long", blueprint["default description"] || "A vehicle.");
        
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
        
        set("cargo", ([]));
        set("crew", ([]));
        
        currentStructure = getMaxStructure();
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int set(string element, mixed data)
{
    int result = 0;
    
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
