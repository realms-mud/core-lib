//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/secure/dataServices/dataService.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping getInventory(int playerId, int dbHandle)
{
    mapping ret = (["inventory":([])]);

    string query = sprintf("select * from inventory "
        "where playerid = '%d'", playerId);
    db_exec(dbHandle, query);

    mixed result;

    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret["inventory"][result[1]] = ([
                "data": convertString(result[2]),
                "isEquipped": to_int(result[3])
            ]);
        }
    } while (result);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void saveInventory(int dbHandle, int playerId, mapping playerData)
{
    string query = sprintf("call pruneInventory(%d);", playerId);
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);

    if (member(playerData, "inventory") &&
        sizeof(playerData["inventory"]))
    {
        string *inventoryItems = m_indices(playerData["inventory"]);
        foreach(string item in inventoryItems)
        {
            query = sprintf("call saveInventoryItem(%d,'%s','%s',%d);",
                playerId,
                sanitizeString(item),
                sanitizeString(playerData["inventory"][item]["data"]),
                playerData["inventory"][item]["isEquipped"]);
            db_exec(dbHandle, query);
            result = db_fetch(dbHandle);
        }
    }
}
