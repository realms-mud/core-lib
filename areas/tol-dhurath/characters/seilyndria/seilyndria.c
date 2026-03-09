//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

private int playerGaveName = 0;

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("woman");
    short("An attractive, but unkempt woman");
    description("A woman dressed in a dirty tan-ish shirt and equally dirty "
        "pants. Both are made of coarse, thread-bare linen and show signs "
        "of excessive mistreatment. There are many stains - some of blood "
        "and some of what appear to be porridge. She smells of sweat, urine, "
        "feces, and rotting food. Her auburn hair is disheveled and rather "
        "filthy. Dirt, bruises, and abrasions mark her face. "
        "All of the abuse and neglect does not obscure the fact that she "
        "is an incredibly attractive woman. Her pale blue eyes open a window "
        "into a tortured, despairing soul.");
    addAlias("woman");
    addAlias("attractive woman");
    addAlias("unkempt woman");

    customCombatAssessment("Unknown");
    Gender("female");
    Race("deity");
    apparentRace("maegenstryd");
    SetUpPersonaOfLevel("aeromancer", 80);
    addTrait("/lib/instances/traits/archetypes/iitj.c");
    addTrait("/lib/instances/traits/educational/tactician.c");
    addTrait("/lib/instances/traits/educational/architect.c");
    addTrait("/lib/instances/traits/educational/articulate.c");
    addTrait("/lib/instances/traits/educational/arcane.c");
    addTrait("/lib/instances/traits/educational/educated.c");
    addTrait("/lib/instances/traits/educational/mastermind.c");
    addTrait("/lib/instances/traits/eyes/light-blue.c");
    addTrait("/lib/instances/traits/genetic/attractive.c");
    addTrait("/lib/instances/traits/genetic/genius.c");
    addTrait("/lib/instances/traits/hair/auburn.c");
    addTrait("/lib/instances/traits/personality/cold.c");
    addTrait("/lib/instances/traits/personality/feared.c");

    addConversation("/areas/tol-dhurath/characters/seilyndria/startingConversation.c");
    addConversation("/areas/tol-dhurath/characters/seilyndria/sealConversation.c");

    registerEventHandler("revealSeilyndria");
    registerEventHandler("revealName");
    registerEventHandler("playerGaveName");
    registerEvent(this_object());
}

/////////////////////////////////////////////////////////////////////////////
public void revealName()
{
    Name("maiwyn");
    short("Maiwyn");
    addAlias("maiwyn");
}

/////////////////////////////////////////////////////////////////////////////
public void revealSeilyndria()
{
    Name("seilyndria");
    short("Seilyndria");
    addAlias("seilyndria");

    description("A woman of terrible beauty stands before you. Her "
        "features are exquisite beyond mortal measure - high cheekbones, "
        "full lips curved in a knowing smile, and eyes of deep violet "
        "that seem to hold the weight of millennia. Her hair flows like "
        "liquid shadow, dark and impossibly long. She wears a gown that "
        "seems woven from twilight itself - shifting between deep purple "
        "and absolute black. An aura of immense power radiates from her, "
        "making the air itself tremble.");
}

/////////////////////////////////////////////////////////////////////////////
public void playerGaveName()
{
    playerGaveName = 1;
}

/////////////////////////////////////////////////////////////////////////////
public string speakPlayerName(object actor)
{
    return playerGaveName ? capitalize(actor.RealName()) : "unnamed ser";
}

/////////////////////////////////////////////////////////////////////////////
public string getDateAndTime(object actor)
{
    return getService("environment")->currentDayAndYear();
}
