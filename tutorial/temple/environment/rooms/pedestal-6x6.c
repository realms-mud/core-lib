//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setInterior("/tutorial/temple/environment/interiors/pedestal-chamber.c");
    addFeature("/tutorial/temple/environment/features/amethyst-floor.c");
    addFeature("/tutorial/temple/environment/features/amethyst-ceiling.c");
    addFeature("/tutorial/temple/environment/features/purple-liquid.c");

    addDecorator("ruined interior west wall");
    addDecorator("ruined interior west entry alcove", "seventh test");

    // Seventh test
    addExit("west", "/tutorial/temple/environment/rooms/pedestal-3x5.c", "seventh test");
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-6x5.c", "seventh test");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");
}

/////////////////////////////////////////////////////////////////////////////
public void placeUhrdalen(object stateMachine, object player)
{
    object uhrdalen = StateMachine ?
        StateMachine->getUhrdalen() : 0;

    if (objectp(uhrdalen))
    {
        uhrdalen->registerEvent(this_object());

        string owner = cloneOwner();
        object location = (owner && member(instances, owner)) ?
            instances[owner] : this_object();
        move_object(uhrdalen, location);

        if (objectp(player) && present(player, location))
        {
            command("talk uhrdalen", player);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public void questCompleted(object uhrdalen, object player)
{
    if (StateMachine && objectp(player))
    {
        StateMachine->receiveEvent(player, "questCompleted");
    }
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    environment::init();

    object player = this_player();

    if (objectp(player) && player->isRealizationOfPlayer())
    {
        object uhrdalen = present("uhrdalen", this_object());

        if (objectp(uhrdalen) && present(player, this_object()))
        {
            call_out("initiateConversation", 1, player);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private void initiateConversation(object player)
{
    if (objectp(player) && present("uhrdalen", this_object()) &&
        present(player, this_object()))
    {
        command("talk uhrdalen", player);
    }
}

/////////////////////////////////////////////////////////////////////////////
public string **customIcon(string **baseIcon, string color, string charset)
{
    string baseColor = getService("region")->iconColor(
        "ruined interior north wall", color);

    baseIcon[0][0] = sprintf("%s%s%s", baseColor,
        (charset == "unicode") ? "\u255d" : "+",
        (baseColor != "") ? "\x1b[0m" : baseColor);

    return baseIcon;
}
