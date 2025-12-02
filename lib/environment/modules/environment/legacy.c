//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/environment/core.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask int isLegacyEnvironment()
{
    return sizeof(environmentalElements["terrain"]) &&
        member(environmentalElements["terrain"], "legacy");
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addLegacyItem(string item, string description)
{
    if (isLegacyEnvironment())
    {
        if (!member(aliasesToElements, "default"))
        {
            aliasesToElements["default"] = ([]);
        }
        aliasesToElements["default"][item] = description;
    }
    else
    {
        raise_error("ERROR in environment.c: addLegacyItem is only "
            "usable when the terrain is in legacy mode.\n");
    }
}
