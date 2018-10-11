//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private int IsBusy = 0;
private int Earmuffs = 0;
private int PageSize = 20;
private mapping blocks = ([ ]);
private string colorSetting = "3-bit";
private string characterSet = "ascii";

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
        "character set": characterSet
    ]);
}
