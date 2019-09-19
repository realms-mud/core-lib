//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private int IsBusy = 0;
private int Earmuffs = 0;
private int PageSize = 20;
private int DisplayMiniMap = 1;
private string PrimaryGuild = 0;
private mapping blocks = ([ ]);
private string colorSetting = "3-bit";
private string characterSet = "ascii";
private int lastSafetyTeleport = 0;
private nosave object ReplyTo;

/////////////////////////////////////////////////////////////////////////////
static nomask void loadSettings(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
        IsBusy = to_int(persistence->extractSaveData("busy", data));
        Earmuffs = to_int(persistence->extractSaveData("earmuffs", data));
        PageSize = to_int(persistence->extractSaveData("page size", data));
        colorSetting = persistence->extractSaveData("color setting", data);
        characterSet = persistence->extractSaveData("character set", data);
        PrimaryGuild = persistence->extractSaveData("primary guild", data);
        lastSafetyTeleport = persistence->extractSaveData("safety teleport", 
            data);
        DisplayMiniMap = to_int(persistence->extractSaveData("display mini map",
            data));
        blocks = persistence->extractSaveData("blocks", data);
    }

    if (!PageSize)
    {
        PageSize = 20;
    }

    if (member(({ "none", "3-bit", "8-bit", "24-bit" }), colorSetting) < 0)
    {
        colorSetting = "3-bit";
    }

    if (member(({ "ascii", "unicode" }), characterSet) < 0)
    {
        characterSet = "ascii";
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask mapping sendSettings()
{
    return ([
        "blocks": blocks,
        "busy": to_string(IsBusy),
        "earmuffs": to_string(Earmuffs),
        "page size": to_string(PageSize),
        "color setting": colorSetting,
        "character set": characterSet,
        "primary guild": PrimaryGuild,
        "safety teleport": lastSafetyTeleport,
        "display mini map": DisplayMiniMap
    ]);
}
