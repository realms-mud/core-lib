//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-magic/dream-touch.c");

    addChild("/guilds/oneiromancer/dream-magic/dream-touch.c",
        "/guilds/oneiromancer/dream-magic/dream-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-magic/slumber-ward.c");
    addResearchElement("/guilds/oneiromancer/dream-magic/waking-dreams.c");

    addChild("/guilds/oneiromancer/dream-magic/slumber-ward.c",
        "/guilds/oneiromancer/dream-magic/dream-touch.c");
    addChild("/guilds/oneiromancer/dream-magic/waking-dreams.c",
        "/guilds/oneiromancer/dream-magic/dream-touch.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-magic/dream-mastery.c");

    addChild("/guilds/oneiromancer/dream-magic/dream-mastery.c",
        "/guilds/oneiromancer/dream-magic/dream-touch.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-magic/dreamscape-shift.c");
    addResearchElement("/guilds/oneiromancer/dream-magic/phantasmal-bolt.c");

    addChild("/guilds/oneiromancer/dream-magic/dreamscape-shift.c",
        "/guilds/oneiromancer/dream-magic/slumber-ward.c");
    addChild("/guilds/oneiromancer/dream-magic/phantasmal-bolt.c",
        "/guilds/oneiromancer/dream-magic/waking-dreams.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-magic/mind-fog.c");
    addResearchElement("/guilds/oneiromancer/dream-magic/dream-sight.c");

    addChild("/guilds/oneiromancer/dream-magic/mind-fog.c",
        "/guilds/oneiromancer/dream-magic/dreamscape-shift.c");
    addChild("/guilds/oneiromancer/dream-magic/dream-sight.c",
        "/guilds/oneiromancer/dream-magic/phantasmal-bolt.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-magic/oneiric-potency.c");

    addChild("/guilds/oneiromancer/dream-magic/oneiric-potency.c",
        "/guilds/oneiromancer/dream-magic/dream-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-magic/nightmare-bolt.c");

    addChild("/guilds/oneiromancer/dream-magic/nightmare-bolt.c",
        "/guilds/oneiromancer/dream-magic/mind-fog.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-magic/sleep-of-ages.c");
    addResearchElement("/guilds/oneiromancer/dream-magic/lucid-strike.c");

    addChild("/guilds/oneiromancer/dream-magic/sleep-of-ages.c",
        "/guilds/oneiromancer/dream-magic/nightmare-bolt.c");
    addChild("/guilds/oneiromancer/dream-magic/lucid-strike.c",
        "/guilds/oneiromancer/dream-magic/dream-sight.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-magic/nightmare-potency.c");

    addChild("/guilds/oneiromancer/dream-magic/nightmare-potency.c",
        "/guilds/oneiromancer/dream-magic/oneiric-potency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-magic/dream-shackles.c");
    addResearchElement("/guilds/oneiromancer/dream-magic/oneiric-blast.c");

    addChild("/guilds/oneiromancer/dream-magic/dream-shackles.c",
        "/guilds/oneiromancer/dream-magic/sleep-of-ages.c");
    addChild("/guilds/oneiromancer/dream-magic/oneiric-blast.c",
        "/guilds/oneiromancer/dream-magic/lucid-strike.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-magic/veil-of-dreams.c");

    addChild("/guilds/oneiromancer/dream-magic/veil-of-dreams.c",
        "/guilds/oneiromancer/dream-magic/dream-shackles.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-magic/dream-rend.c");
    addResearchElement("/guilds/oneiromancer/dream-magic/somnolent-aura.c");

    addChild("/guilds/oneiromancer/dream-magic/dream-rend.c",
        "/guilds/oneiromancer/dream-magic/veil-of-dreams.c");
    addChild("/guilds/oneiromancer/dream-magic/somnolent-aura.c",
        "/guilds/oneiromancer/dream-magic/oneiric-blast.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-magic/mind-prison.c");

    addChild("/guilds/oneiromancer/dream-magic/mind-prison.c",
        "/guilds/oneiromancer/dream-magic/dream-rend.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-magic/dream-tempest.c");
    addResearchElement("/guilds/oneiromancer/dream-magic/psychic-fortress.c");

    addChild("/guilds/oneiromancer/dream-magic/dream-tempest.c",
        "/guilds/oneiromancer/dream-magic/mind-prison.c");
    addChild("/guilds/oneiromancer/dream-magic/psychic-fortress.c",
        "/guilds/oneiromancer/dream-magic/somnolent-aura.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-magic/nightmare-cascade.c");

    addChild("/guilds/oneiromancer/dream-magic/nightmare-cascade.c",
        "/guilds/oneiromancer/dream-magic/dream-tempest.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySeventhLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-magic/dreamwalk.c");
    addResearchElement("/guilds/oneiromancer/dream-magic/mental-annihilation.c");

    addChild("/guilds/oneiromancer/dream-magic/dreamwalk.c",
        "/guilds/oneiromancer/dream-magic/nightmare-cascade.c");
    addChild("/guilds/oneiromancer/dream-magic/mental-annihilation.c",
        "/guilds/oneiromancer/dream-magic/psychic-fortress.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-magic/realm-of-nightmares.c");

    addChild("/guilds/oneiromancer/dream-magic/realm-of-nightmares.c",
        "/guilds/oneiromancer/dream-magic/dreamwalk.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFifthLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-magic/dream-cataclysm.c");
    addResearchElement("/guilds/oneiromancer/dream-magic/eternal-slumber.c");

    addChild("/guilds/oneiromancer/dream-magic/dream-cataclysm.c",
        "/guilds/oneiromancer/dream-magic/realm-of-nightmares.c");
    addChild("/guilds/oneiromancer/dream-magic/eternal-slumber.c",
        "/guilds/oneiromancer/dream-magic/mental-annihilation.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyNinthLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-magic/oneiric-apocalypse.c");

    addChild("/guilds/oneiromancer/dream-magic/oneiric-apocalypse.c",
        "/guilds/oneiromancer/dream-magic/dream-cataclysm.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-magic/master-of-dreams.c");
    addResearchElement("/guilds/oneiromancer/dream-magic/sleep-eternal.c");

    addChild("/guilds/oneiromancer/dream-magic/master-of-dreams.c",
        "/guilds/oneiromancer/dream-magic/oneiric-apocalypse.c");
    addChild("/guilds/oneiromancer/dream-magic/sleep-eternal.c",
        "/guilds/oneiromancer/dream-magic/eternal-slumber.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-magic/dream-god.c");

    addChild("/guilds/oneiromancer/dream-magic/dream-god.c",
        "/guilds/oneiromancer/dream-magic/master-of-dreams.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Dream Magic");
    Description("This research tree provides knowledge of dream magic - the "
        "core discipline of the oneiromancer. Through study of the dreaming "
        "realm, practitioners learn to weave illusions, assault minds with "
        "nightmarish visions, and eventually master the boundary between "
        "dreams and reality itself.");
    Source("oneiromancer");
    addResearchElement("/guilds/oneiromancer/dream-magic/dream-root.c");
    TreeRoot("/guilds/oneiromancer/dream-magic/dream-root.c");

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
