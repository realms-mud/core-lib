//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/thing.c";

private string location = "";
private int capacity = 10000;
private mapping inventory = ([]);

/////////////////////////////////////////////////////////////////////////////
public void setLocation(string loc)
{
    location = loc;
}

/////////////////////////////////////////////////////////////////////////////
public string getLocation()
{
    return location;
}

/////////////////////////////////////////////////////////////////////////////
public void setCapacity(int cap)
{
    capacity = cap;
}

/////////////////////////////////////////////////////////////////////////////
public int getCapacity()
{
    return capacity;
}

/////////////////////////////////////////////////////////////////////////////
public mapping getInventory()
{
    return inventory + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public int getUsedSpace()
{
    int used = 0;
    if (mappingp(inventory))
    {
        foreach (string item in m_indices(inventory))
        {
            used += inventory[item];
        }
    }
    return used;
}

/////////////////////////////////////////////////////////////////////////////
public int getFreeSpace()
{
    return capacity - getUsedSpace();
}

/////////////////////////////////////////////////////////////////////////////
public int getCargoQuantity(string item)
{
    int ret = 0;
    if (stringp(item) && member(inventory, item))
    {
        ret = inventory[item];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int addCargo(string item, int quantity)
{
    int ret = 0;
    if (stringp(item) && intp(quantity) && (getFreeSpace() >= quantity) && (quantity > 0))
    {
        if (!member(inventory, item))
        {
            inventory[item] = 0;
        }
        inventory[item] += quantity;
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int removeCargo(string item, int quantity)
{
    int ret = 0;
    if (stringp(item) && intp(quantity) && member(inventory, item) && (inventory[item] >= quantity) && (quantity > 0))
    {
        inventory[item] -= quantity;
        if (inventory[item] <= 0)
        {
            m_delete(inventory, item);
        }
        ret = 1;
    }
    return ret;
}
