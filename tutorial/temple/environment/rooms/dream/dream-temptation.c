//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
private string *colorInfo()
{
    object user = this_player();
    string colorConfig = (objectp(user) && user->colorConfiguration()) ?
        user->colorConfiguration() : "none";
    string closing = (colorConfig == "none") ? "" : "\x1b[0m";
    return ({ colorConfig, closing });
}

/////////////////////////////////////////////////////////////////////////////
private mapping dreamColors()
{
    object dreamEntry =
        load_object("/tutorial/temple/environment/rooms/dream/dream-entry.c");
    return dreamEntry->getDreamColors();
}

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/tutorial/temple/environment/interiors/pedestal-chamber.c");
    addFeature("/tutorial/temple/environment/features/amethyst-floor.c");
    addFeature("/tutorial/temple/environment/features/amethyst-ceiling.c");

    addExit("north",
        "/tutorial/temple/environment/rooms/dream/dream-bargain.c");
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    ::init();

    if (present(this_player()))
    {
        add_action("dreamChoice", "accept");
        add_action("dreamChoice", "refuse");

        string *ci = colorInfo();
        mapping colors = dreamColors();

        tell_object(this_player(), format(
            colors["vision"][ci[0]] +
            "A figure of terrible beauty stands before you — "
            "Xyris, the Lord of Shadows, as he appeared in life. His voice "
            "is honey and venom.\n\n"
            "@S@'You are gifted, young one. I see in you the potential for "
            "greatness beyond the petty ambitions of your peers. Serve me "
            "and I shall grant you knowledge that others would kill for. "
            "All I ask is a small oath of loyalty.'\n\n"
            "You may 'accept' the oath or 'refuse' it. Remember: you are "
            "reliving what was, not what should have been." +
            ci[1] + "\n", 78));
    }
}

/////////////////////////////////////////////////////////////////////////////
public int dreamChoice(string str)
{
    string verb = query_verb();
    object dreamEntry =
        load_object("/tutorial/temple/environment/rooms/dream/dream-entry.c");
    mapping colors = dreamEntry->getDreamColors();
    string *ci = colorInfo();

    if (verb == "accept")
    {
        tell_object(this_player(),
            colors["vision"][ci[0]] +
            "You kneel and speak the oath. Xyris smiles — a "
            "terrible, beautiful thing. Power floods through you like "
            "fire." + ci[1] + "\n");
        dreamEntry->advanceDream(this_player(), "accept");

        if (present(this_player(), this_object()))
        {
            tell_object(this_player(), "A corridor leads north.\n");
        }
        return 1;
    }
    else if (verb == "refuse")
    {
        tell_object(this_player(),
            colors["failure"][ci[0]] +
            "You refuse the oath. Noble... but wrong. This "
            "is not what happened." + ci[1] + "\n");
        dreamEntry->resetDream(this_player());
        return 1;
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public string suppressDeath()
{
    return "The dream protects you from true death, but the pain "
        "feels very real.\n";
}
