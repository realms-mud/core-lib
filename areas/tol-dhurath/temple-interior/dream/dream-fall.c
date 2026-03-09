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
    setInterior("/areas/tol-dhurath/interiors/pedestal-chamber.c");
    addFeature("/areas/tol-dhurath/features/amethyst-floor.c");
    addFeature("/areas/tol-dhurath/features/amethyst-ceiling.c");
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    ::init();

    if (present(this_player()))
    {
        add_action("dreamChoice", "submit");
        add_action("dreamChoice", "break");

        string *ci = colorInfo();
        object dreamEntry =
            load_object("/areas/tol-dhurath/temple-interior/dream/dream-entry.c");
        mapping colors = dreamEntry->getDreamColors();

        tell_object(this_player(), format(
            colors["vision"][ci[0]] +
            "The city is ash. A broken talisman lies at your "
            "feet - the last gift from someone you once loved. Xyris's "
            "voice comes one final time.\n\n"
            "@S@'You have proven your worth. Now I bind you to this place "
            "as its eternal guardian. Your flesh shall wither but your "
            "spirit shall endure. This is my final command.'\n\n"
            "The chains of light descend. You may 'submit' to the binding "
            "or 'break' free. But Uhrdalen did not break free. Not then. "
            "That came much, much later - as a skeleton tending runes "
            "on a wall, waiting for someone like you." +
            ci[1] + "\n", 78));
    }
}

/////////////////////////////////////////////////////////////////////////////
public int dreamChoice(string str)
{
    string verb = query_verb();
    object dreamEntry =
        load_object("/areas/tol-dhurath/temple-interior/dream/dream-entry.c");
    mapping colors = dreamEntry->getDreamColors();
    string *ci = colorInfo();

    if (verb == "submit")
    {
        tell_object(this_player(),
            colors["vision"][ci[0]] +
            "You submit. The chains close around you. The "
            "centuries begin. You feel Uhrdalen's loneliness, his regret, "
            "his slow understanding that obedience without wisdom is "
            "slavery. The weight of ages presses down..." +
            ci[1] + "\n");
        dreamEntry->advanceDream(this_player(), "submit");
        return 1;
    }
    else if (verb == "break")
    {
        tell_object(this_player(),
            colors["failure"][ci[0]] +
            "You try to break free. If only Uhrdalen had. "
            "But he did not - not in this moment." + ci[1] + "\n");
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
