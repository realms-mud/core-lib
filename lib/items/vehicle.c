//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/item.c";

private object vehicleDictionary;
private int currentStructure = -1;

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    vehicleDictionary = getDictionary("vehicle");
    if (!objectp(vehicleDictionary))
    {
        raise_error("vehicle.c: Could not load vehicleDictionary.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getBlueprint()
{
    mapping result = ([]);
    string type = query("vehicle type");
    if (stringp(type) && objectp(vehicleDictionary))
    {
        result = vehicleDictionary->queryVehicleBlueprint(type);
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
        if (stringp(name) && objectp(vehicleDictionary))
        {
            result = vehicleDictionary->queryComponent(name);
        }
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getAllComponentsWithDetails()
{
    mapping result = ([]);
    mapping components = query("components");
    if (mappingp(components) && objectp(vehicleDictionary))
    {
        string *slots = m_indices(components);
        foreach(string slot in slots)
        {
            string name = components[slot];
            if (stringp(name))
            {
                result[slot] = vehicleDictionary->queryComponent(name);
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
    return base;
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
    int freeSpace = getCapacity() - getUsedSpace();
    return freeSpace;
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
    // Optionally add crew/research bonuses here
    return prot;
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
                power += comp["weight"]; // Or use a more specific stat if available
            }
        }
    }
    // Optionally add crew/research bonuses here
    return power;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getDefense()
{
    int defense = getTradeProtection();
    // Optionally add crew/research bonuses here
    return defense;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getSpeed()
{
    int speed = 0;
    mapping blueprint = getBlueprint();
    if (mappingp(blueprint) && member(blueprint, "speed"))
    {
        speed = blueprint["speed"];
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
    // Optionally add crew/research bonuses here
    return speed;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int installComponent(string slot, string componentName)
{
    int result = 0;
    mapping components = query("components") || ([]);
    if (objectp(vehicleDictionary) && vehicleDictionary->queryComponent(componentName))
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
    if (member(components, slot))
    {
        m_delete(components, slot);
        set("components", components);
        result = 1;
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
public nomask void removeCrew(string role)
{
    mapping crew = query("crew") || ([]);
    if (role && member(crew, role))
    {
        m_delete(crew, role);
        set("crew", crew);
    }
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
    return getCurrentStructure() <= 0;
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
public nomask varargs int set(string element, mixed data)
{
    // Enforce required elements for vehicles
    switch (element)
    {
        case "vehicle type":
        {
            if (!data || !stringp(data) || !vehicleDictionary->queryVehicleBlueprint(data))
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
    return item::set(element, data);
}
