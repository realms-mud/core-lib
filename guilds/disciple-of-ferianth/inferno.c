//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/inferno/flame-touch.c");

    addChild("/guilds/disciple-of-ferianth/inferno/flame-touch.c",
        "/guilds/disciple-of-ferianth/inferno/inferno-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/inferno/searing-light.c");
    addResearchElement("/guilds/disciple-of-ferianth/inferno/kindle.c");

    addChild("/guilds/disciple-of-ferianth/inferno/searing-light.c",
        "/guilds/disciple-of-ferianth/inferno/flame-touch.c");
    addChild("/guilds/disciple-of-ferianth/inferno/kindle.c",
        "/guilds/disciple-of-ferianth/inferno/flame-touch.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/inferno/fire-mastery.c");

    addChild("/guilds/disciple-of-ferianth/inferno/fire-mastery.c",
        "/guilds/disciple-of-ferianth/inferno/flame-touch.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/inferno/fire-bolt.c");
    addResearchElement("/guilds/disciple-of-ferianth/inferno/heat-metal.c");

    addChild("/guilds/disciple-of-ferianth/inferno/fire-bolt.c",
        "/guilds/disciple-of-ferianth/inferno/searing-light.c");
    addChild("/guilds/disciple-of-ferianth/inferno/heat-metal.c",
        "/guilds/disciple-of-ferianth/inferno/kindle.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/inferno/burning-hands.c");
    addResearchElement("/guilds/disciple-of-ferianth/inferno/flame-lash.c");

    addChild("/guilds/disciple-of-ferianth/inferno/burning-hands.c",
        "/guilds/disciple-of-ferianth/inferno/fire-bolt.c");
    addChild("/guilds/disciple-of-ferianth/inferno/flame-lash.c",
        "/guilds/disciple-of-ferianth/inferno/heat-metal.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/inferno/inferno-potency.c");

    addChild("/guilds/disciple-of-ferianth/inferno/inferno-potency.c",
        "/guilds/disciple-of-ferianth/inferno/fire-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/inferno/fireball.c");

    addChild("/guilds/disciple-of-ferianth/inferno/fireball.c",
        "/guilds/disciple-of-ferianth/inferno/burning-hands.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/inferno/pillar-of-fire.c");
    addResearchElement("/guilds/disciple-of-ferianth/inferno/scorching-ray.c");

    addChild("/guilds/disciple-of-ferianth/inferno/pillar-of-fire.c",
        "/guilds/disciple-of-ferianth/inferno/fireball.c");
    addChild("/guilds/disciple-of-ferianth/inferno/scorching-ray.c",
        "/guilds/disciple-of-ferianth/inferno/flame-lash.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/inferno/divine-fire-potency.c");

    addChild("/guilds/disciple-of-ferianth/inferno/divine-fire-potency.c",
        "/guilds/disciple-of-ferianth/inferno/inferno-potency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/inferno/flame-strike.c");
    addResearchElement("/guilds/disciple-of-ferianth/inferno/incinerate.c");

    addChild("/guilds/disciple-of-ferianth/inferno/flame-strike.c",
        "/guilds/disciple-of-ferianth/inferno/pillar-of-fire.c");
    addChild("/guilds/disciple-of-ferianth/inferno/incinerate.c",
        "/guilds/disciple-of-ferianth/inferno/scorching-ray.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/inferno/wall-of-fire.c");

    addChild("/guilds/disciple-of-ferianth/inferno/wall-of-fire.c",
        "/guilds/disciple-of-ferianth/inferno/flame-strike.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/inferno/fire-storm.c");
    addResearchElement("/guilds/disciple-of-ferianth/inferno/consuming-flames.c");

    addChild("/guilds/disciple-of-ferianth/inferno/fire-storm.c",
        "/guilds/disciple-of-ferianth/inferno/wall-of-fire.c");
    addChild("/guilds/disciple-of-ferianth/inferno/consuming-flames.c",
        "/guilds/disciple-of-ferianth/inferno/incinerate.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/inferno/immolation.c");

    addChild("/guilds/disciple-of-ferianth/inferno/immolation.c",
        "/guilds/disciple-of-ferianth/inferno/fire-storm.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/inferno/hellfire.c");
    addResearchElement("/guilds/disciple-of-ferianth/inferno/blazing-wrath.c");

    addChild("/guilds/disciple-of-ferianth/inferno/hellfire.c",
        "/guilds/disciple-of-ferianth/inferno/immolation.c");
    addChild("/guilds/disciple-of-ferianth/inferno/blazing-wrath.c",
        "/guilds/disciple-of-ferianth/inferno/consuming-flames.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/inferno/infernal-blast.c");

    addChild("/guilds/disciple-of-ferianth/inferno/infernal-blast.c",
        "/guilds/disciple-of-ferianth/inferno/hellfire.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/inferno/rain-of-fire.c");
    addResearchElement("/guilds/disciple-of-ferianth/inferno/soulfire.c");

    addChild("/guilds/disciple-of-ferianth/inferno/rain-of-fire.c",
        "/guilds/disciple-of-ferianth/inferno/infernal-blast.c");
    addChild("/guilds/disciple-of-ferianth/inferno/soulfire.c",
        "/guilds/disciple-of-ferianth/inferno/blazing-wrath.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/inferno/ferianths-fury.c");

    addChild("/guilds/disciple-of-ferianth/inferno/ferianths-fury.c",
        "/guilds/disciple-of-ferianth/inferno/rain-of-fire.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/inferno/solar-flare.c");
    addResearchElement("/guilds/disciple-of-ferianth/inferno/purging-flames.c");

    addChild("/guilds/disciple-of-ferianth/inferno/solar-flare.c",
        "/guilds/disciple-of-ferianth/inferno/ferianths-fury.c");
    addChild("/guilds/disciple-of-ferianth/inferno/purging-flames.c",
        "/guilds/disciple-of-ferianth/inferno/soulfire.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyNinthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/inferno/divine-conflagration.c");

    addChild("/guilds/disciple-of-ferianth/inferno/divine-conflagration.c",
        "/guilds/disciple-of-ferianth/inferno/solar-flare.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/inferno/wrath-of-ferianth.c");
    addResearchElement("/guilds/disciple-of-ferianth/inferno/celestial-inferno.c");

    addChild("/guilds/disciple-of-ferianth/inferno/wrath-of-ferianth.c",
        "/guilds/disciple-of-ferianth/inferno/divine-conflagration.c");
    addChild("/guilds/disciple-of-ferianth/inferno/celestial-inferno.c",
        "/guilds/disciple-of-ferianth/inferno/purging-flames.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/inferno/apocalyptic-fire.c");

    addChild("/guilds/disciple-of-ferianth/inferno/apocalyptic-fire.c",
        "/guilds/disciple-of-ferianth/inferno/wrath-of-ferianth.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Inferno");
    Description("This research tree provides knowledge of offensive fire magic - "
        "the primary weapon of the Disciples of Ferianth. Through study of "
        "sacred flames, practitioners learn to call forth divine fire to "
        "smite their enemies, from simple flames to apocalyptic conflagrations "
        "that embody Ferianth's righteous fury.");
    Source("disciple of ferianth");
    addResearchElement("/guilds/disciple-of-ferianth/inferno/inferno-root.c");
    TreeRoot("/guilds/disciple-of-ferianth/inferno/inferno-root.c");

    FirstLevel();
    ThirdLevel();
    FifthLevel();
    SeventhLevel();
    EleventhLevel();
    ThirteenthLevel();
    FifteenthLevel();
    NineteenthLevel();
    TwentyFirstLevel();
    TwentyThirdLevel();
    TwentySeventhLevel();
    ThirtyFirstLevel();
    ThirtyFifthLevel();
    ThirtyNinthLevel();
    FortyThirdLevel();
    FortySeventhLevel();
    FiftyFirstLevel();
    FiftyFifthLevel();
    FiftyNinthLevel();
    SixtyThirdLevel();
    SixtySeventhLevel();
}
