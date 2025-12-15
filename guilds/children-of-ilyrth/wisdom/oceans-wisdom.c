//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/wisdom/tidal-insight.c");

    addChild("/guilds/children-of-ilyrth/wisdom/tidal-insight.c",
        "/guilds/children-of-ilyrth/wisdom/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/wisdom/waters-clarity.c");
    addResearchElement("/guilds/children-of-ilyrth/wisdom/depths-perception.c");

    addChild("/guilds/children-of-ilyrth/wisdom/waters-clarity.c",
        "/guilds/children-of-ilyrth/wisdom/tidal-insight.c");
    addChild("/guilds/children-of-ilyrth/wisdom/depths-perception.c",
        "/guilds/children-of-ilyrth/wisdom/tidal-insight.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/wisdom/sea-sense.c");
    addResearchElement("/guilds/children-of-ilyrth/wisdom/current-awareness.c");

    addChild("/guilds/children-of-ilyrth/wisdom/sea-sense.c",
        "/guilds/children-of-ilyrth/wisdom/waters-clarity.c");
    addChild("/guilds/children-of-ilyrth/wisdom/current-awareness.c",
        "/guilds/children-of-ilyrth/wisdom/depths-perception.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/wisdom/tidal-foresight.c");
    addResearchElement("/guilds/children-of-ilyrth/wisdom/echo-location.c");

    addChild("/guilds/children-of-ilyrth/wisdom/tidal-foresight.c",
        "/guilds/children-of-ilyrth/wisdom/sea-sense.c");
    addChild("/guilds/children-of-ilyrth/wisdom/echo-location.c",
        "/guilds/children-of-ilyrth/wisdom/sea-sense.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/wisdom/ocean-divination.c");
    addResearchElement("/guilds/children-of-ilyrth/wisdom/pressure-sense.c");

    addChild("/guilds/children-of-ilyrth/wisdom/ocean-divination.c",
        "/guilds/children-of-ilyrth/wisdom/tidal-foresight.c");
    addChild("/guilds/children-of-ilyrth/wisdom/pressure-sense.c",
        "/guilds/children-of-ilyrth/wisdom/current-awareness.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/wisdom/deep-knowing.c");
    addResearchElement("/guilds/children-of-ilyrth/wisdom/wave-whispers.c");

    addChild("/guilds/children-of-ilyrth/wisdom/deep-knowing.c",
        "/guilds/children-of-ilyrth/wisdom/ocean-divination.c");
    addChild("/guilds/children-of-ilyrth/wisdom/wave-whispers.c",
        "/guilds/children-of-ilyrth/wisdom/echo-location.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/wisdom/abyssal-sight.c");
    addResearchElement("/guilds/children-of-ilyrth/wisdom/currents-truth.c");

    addChild("/guilds/children-of-ilyrth/wisdom/abyssal-sight.c",
        "/guilds/children-of-ilyrth/wisdom/pressure-sense.c");
    addChild("/guilds/children-of-ilyrth/wisdom/currents-truth.c",
        "/guilds/children-of-ilyrth/wisdom/deep-knowing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/wisdom/ilryths-vision.c");

    addChild("/guilds/children-of-ilyrth/wisdom/ilryths-vision.c",
        "/guilds/children-of-ilyrth/wisdom/wave-whispers.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/wisdom/prophetic-tides.c");
    addResearchElement("/guilds/children-of-ilyrth/wisdom/seas-memory.c");

    addChild("/guilds/children-of-ilyrth/wisdom/prophetic-tides.c",
        "/guilds/children-of-ilyrth/wisdom/abyssal-sight.c");
    addChild("/guilds/children-of-ilyrth/wisdom/seas-memory.c",
        "/guilds/children-of-ilyrth/wisdom/currents-truth.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/wisdom/divine-perception.c");

    addChild("/guilds/children-of-ilyrth/wisdom/divine-perception.c",
        "/guilds/children-of-ilyrth/wisdom/ilryths-vision.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/wisdom/trench-sight.c");
    addResearchElement("/guilds/children-of-ilyrth/wisdom/tidal-intuition.c");

    addChild("/guilds/children-of-ilyrth/wisdom/trench-sight.c",
        "/guilds/children-of-ilyrth/wisdom/prophetic-tides.c");
    addChild("/guilds/children-of-ilyrth/wisdom/tidal-intuition.c",
        "/guilds/children-of-ilyrth/wisdom/seas-memory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/wisdom/oracle-of-depths.c");
    addResearchElement("/guilds/children-of-ilyrth/wisdom/ocean-omniscience.c");

    addChild("/guilds/children-of-ilyrth/wisdom/oracle-of-depths.c",
        "/guilds/children-of-ilyrth/wisdom/divine-perception.c");
    addChild("/guilds/children-of-ilyrth/wisdom/ocean-omniscience.c",
        "/guilds/children-of-ilyrth/wisdom/trench-sight.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/wisdom/ilryths-insight.c");

    addChild("/guilds/children-of-ilyrth/wisdom/ilryths-insight.c",
        "/guilds/children-of-ilyrth/wisdom/tidal-intuition.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/wisdom/primordial-awareness.c");
    addResearchElement("/guilds/children-of-ilyrth/wisdom/eternal-tides.c");

    addChild("/guilds/children-of-ilyrth/wisdom/primordial-awareness.c",
        "/guilds/children-of-ilyrth/wisdom/oracle-of-depths.c");
    addChild("/guilds/children-of-ilyrth/wisdom/eternal-tides.c",
        "/guilds/children-of-ilyrth/wisdom/ocean-omniscience.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/wisdom/divine-foresight.c");

    addChild("/guilds/children-of-ilyrth/wisdom/divine-foresight.c",
        "/guilds/children-of-ilyrth/wisdom/ilryths-insight.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/wisdom/voice-of-the-deep.c");
    addResearchElement("/guilds/children-of-ilyrth/wisdom/infinite-depths.c");

    addChild("/guilds/children-of-ilyrth/wisdom/voice-of-the-deep.c",
        "/guilds/children-of-ilyrth/wisdom/primordial-awareness.c");
    addChild("/guilds/children-of-ilyrth/wisdom/infinite-depths.c",
        "/guilds/children-of-ilyrth/wisdom/eternal-tides.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/wisdom/ilryths-omniscience.c");

    addChild("/guilds/children-of-ilyrth/wisdom/ilryths-omniscience.c",
        "/guilds/children-of-ilyrth/wisdom/divine-foresight.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/wisdom/avatar-of-wisdom.c");

    addChild("/guilds/children-of-ilyrth/wisdom/avatar-of-wisdom.c",
        "/guilds/children-of-ilyrth/wisdom/voice-of-the-deep.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/wisdom/cosmic-tides.c");

    addChild("/guilds/children-of-ilyrth/wisdom/cosmic-tides.c",
        "/guilds/children-of-ilyrth/wisdom/ilryths-omniscience.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/wisdom/divine-enlightenment.c");

    addChild("/guilds/children-of-ilyrth/wisdom/divine-enlightenment.c",
        "/guilds/children-of-ilyrth/wisdom/avatar-of-wisdom.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/children-of-ilyrth/wisdom/one-with-the-sea.c");

    addChild("/guilds/children-of-ilyrth/wisdom/one-with-the-sea.c",
        "/guilds/children-of-ilyrth/wisdom/divine-enlightenment.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Path of Oceans Wisdom");
    Description("This research tree provides knowledge of divination and "
        "perception channeled through the divine power of Ilyrth, goddess "
        "of the sea. Her followers learn to perceive hidden truths, gain "
        "foresight into future events, and understand the world through "
        "the timeless wisdom of the eternal ocean.");
    Source("Children of Ilyrth");
    addResearchElement("/guilds/children-of-ilyrth/wisdom/root.c");
    TreeRoot("/guilds/children-of-ilyrth/wisdom/root.c");

    FirstLevel();
    ThirdLevel();
    FifthLevel();
    SeventhLevel();
    NinthLevel();
    EleventhLevel();
    ThirteenthLevel();
    FifteenthLevel();
    SeventeenthLevel();
    NineteenthLevel();
    TwentyFirstLevel();
    TwentyFifthLevel();
    TwentyNinthLevel();
    ThirtyThirdLevel();
    ThirtySeventhLevel();
    FortyFirstLevel();
    FortyFifthLevel();
    FiftyFirstLevel();
    FiftySeventhLevel();
    SixtyThirdLevel();
    SixtySeventhLevel();
}
