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
public void Setup()
{
    setInterior("/tutorial/temple/environment/interiors/pedestal-chamber.c");
    addFeature("/tutorial/temple/environment/features/amethyst-floor.c");
    addFeature("/tutorial/temple/environment/features/amethyst-ceiling.c");

    addExit("north",
        "/tutorial/temple/environment/rooms/dream/dream-fall.c");
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    ::init();

    if (present(this_player()))
    {
        add_action("dreamChoice", "obey");
        add_action("dreamChoice", "defy");

        string *ci = colorInfo();
        object dreamEntry =
            load_object("/tutorial/temple/environment/rooms/dream/dream-entry.c");
        mapping colors = dreamEntry->getDreamColors();

        tell_object(this_player(), format(
            colors["vision"][ci[0]] +
            "Time has passed. You stand in a tower overlooking "
            "a city. Xyris's voice fills your mind.\n\n"
            "@S@'The city below shelters those who would oppose me. You "
            "hold the staff I gave you. Speak the word and it will burn. "
            "Disobey and you will lose everything I have given you.'\n\n"
            "The staff thrums with power in your hands. The city is full "
            "of innocents. You may 'obey' and speak the word, or 'defy' "
            "Xyris. What did Uhrdalen do?" + ci[1] + "\n", 78));
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

    if (verb == "obey")
    {
        tell_object(this_player(),
            colors["vision"][ci[0]] +
            "You speak the word. The city burns. You watch "
            "from the tower as screams rise with the smoke. This is the "
            "price of obedience without understanding." + ci[1] + "\n");
        dreamEntry->advanceDream(this_player(), "obey");

        if (present(this_player(), this_object()))
        {
            tell_object(this_player(), "A corridor leads north.\n");
        }
        return 1;
    }
    else if (verb == "defy")
    {
        tell_object(this_player(),
            colors["failure"][ci[0]] +
            "You refuse. Heroic — but Uhrdalen did not refuse. "
            "Not then. Not yet." + ci[1] + "\n");
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
