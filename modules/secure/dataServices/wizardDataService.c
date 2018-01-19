//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/secure/dataServices/dataService.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping getWizardLevel(int playerId, int dbHandle)
{
    mapping ret = ([]);

    string query = sprintf("select type from wizardTypes "
        "inner join wizards on wizards.typeId = wizardTypes.id "
        "and playerid = '%d'", playerId);
    db_exec(dbHandle, query);

    mixed result;
    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret["wizard level"] = result[0];
        }
    } while (result);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void saveWizardLevel(int dbHandle, int playerId, mapping playerData)
{
    if (member(playerData, "wizard level"))
    {
        string query = sprintf("call saveWizardLevel(%d,'%s');",
            playerId,
            sanitizeString(playerData["wizard level"] || ""));

        db_exec(dbHandle, query);
        mixed result = db_fetch(dbHandle);
    }
}
