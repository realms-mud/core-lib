//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib/services/vehicles/vehicles.h"
#include "/lib/services/vehicles/vehicle-components.h"

/////////////////////////////////////////////////////////////////////////////
public nomask mapping queryVehicleBlueprint(string type)
{
    mapping result = ([]);
    if (member(Vehicles, type))
    {
        result = Vehicles[type] + ([]);
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping queryComponent(string name)
{
    mapping result = ([]);
    if (member(VehicleComponents, name))
    {
        result = VehicleComponents[name] + ([]);
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *queryAllVehicleTypes()
{
    return m_indices(Vehicles);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *queryAllComponents()
{
    return m_indices(VehicleComponents);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *queryComponentsByClass(string className)
{
    string *result = ({});
    foreach(string key in m_indices(VehicleComponents))
    {
        if (member(VehicleComponents[key], "class") &&
            VehicleComponents[key]["class"] == className)
        {
            result += ({ key });
        }
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *queryValidComponentsForVehicle(string type)
{
    string *result = queryAllComponents();
    mapping blueprint = queryVehicleBlueprint(type);
    if (sizeof(blueprint) && member(blueprint, "valid components"))
    {
        result = blueprint["valid components"];
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int vehicleIsTradeCapable(object vehicle)
{
    int result = 0;
    if (objectp(vehicle))
    {
        mapping components = vehicle->getComponents();
        if (mappingp(components))
        {
            foreach(string slot in m_indices(components))
            {
                mapping comp = queryComponent(components[slot]);
                if (mappingp(comp) && member(comp, "class") && comp["class"] == "cargo")
                {
                    result = 1;
                    break;
                }
            }
        }
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getVehicleTradeBonus(object vehicle)
{
    int bonus = 0;
    if (objectp(vehicle))
    {
        mapping components = vehicle->getComponents();
        if (mappingp(components))
        {
            foreach(string slot in m_indices(components))
            {
                string name = components[slot];
                if (stringp(name) && sizeof(regexp(({ lower_case(name) }), "arcane")))
                {
                    mapping comp = queryComponent(name);
                    if (mappingp(comp) && member(comp, "class") && comp["class"] == "cargo")
                    {
                        bonus += 10;
                    }
                }
            }
        }
        mapping blueprint = queryVehicleBlueprint(vehicle->query("vehicle type"));
        if (mappingp(blueprint) && member(blueprint, "trade bonus"))
        {
            bonus += blueprint["trade bonus"];
        }
    }
    return bonus;
}

/////////////////////////////////////////////////////////////////////////////
private string getComponentDecoratorKey(string componentName, mapping component)
{
    string lowerName = lower_case(componentName);
    string classType = component["class"];
    string key = classType;

    if (sizeof(regexp(({ lowerName }), "unbuilt")))
    {
        key = "unbuilt " + classType;
    }
    else if (sizeof(regexp(({ lowerName }), "arcane")) ||
             sizeof(regexp(({ lowerName }), "magical")) ||
             (classType == "arcane"))
    {
        key = "arcane " + classType;
    }
    else if (sizeof(regexp(({ lowerName }), "reinforced")))
    {
        key = "reinforced " + classType;
    }
    return key;
}

/////////////////////////////////////////////////////////////////////////////
private string getComponentDisplay(object player, string slotKey, object vehicle)
{
    string componentName = slotKey;
    mapping components = vehicle->getComponents();
    mapping component = ([]);

    if (mappingp(components) && member(components, slotKey))
    {
        componentName = components[slotKey];
        component = queryComponent(componentName);
    }

    string colorConfig = (player && function_exists("colorConfiguration", player)) ?
        player->colorConfiguration() : "none";
    object configDict = getService("configuration");
    string decoratorKey = (mappingp(component) && sizeof(component))
        ? getComponentDecoratorKey(componentName, component)
        : "default";

    string result = componentName;
    if (configDict)
    {
        result = configDict->decorate(componentName, decoratorKey, "vehicle", colorConfig);
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
private string tagReplaceCallback(string tag, mapping slots, object player, object vehicle)
{
    string slot = regreplace(tag, "^\\[([A-Z0-9_ ]+)\\]$", "\\1", 1);
    slot = lower_case(regreplace(slot, " +$", "", 1));
    string result = regreplace(tag, ".", " ", 0);
    if (member(m_indices(slots), slot))
    {
        result = getComponentDisplay(player, slot, vehicle);
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
private string replaceTagsWithComponents(string layout, mapping slots, object player, object vehicle)
{
    string result = regreplace(
        layout,
        "\\[[A-Z0-9_ ]+\\]",
        function string (string tag) { return tagReplaceCallback(tag, slots, player, vehicle); },
        1
    );
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string visualizeVehicle(object player, object vehicle)
{
    string result = "";
    if (objectp(vehicle) && objectp(player) &&
        function_exists("query", vehicle) && function_exists("charset", player))
    {
        string type = vehicle->query("vehicle type");
        mapping data = queryVehicleBlueprint(type);
        string charset = player->charset();
        string layout = (member(data, "layout") && member(data["layout"], charset)) ?
            data["layout"][charset] : "";
        mapping slots = member(data, "slots") ? data["slots"] : ([]);
        result = replaceTagsWithComponents(layout, slots, player, vehicle);
    }
    return result;
}
