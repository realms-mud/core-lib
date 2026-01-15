//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/flame-sight.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/flame-sight.c",
        "/guilds/disciple-of-ferianth/ember-arts/ember-arts-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/kindle-spirit.c");
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/inner-fire.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/kindle-spirit.c",
        "/guilds/disciple-of-ferianth/ember-arts/flame-sight.c");
    addChild("/guilds/disciple-of-ferianth/ember-arts/inner-fire.c",
        "/guilds/disciple-of-ferianth/ember-arts/flame-sight.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/ember-mastery.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/ember-mastery.c",
        "/guilds/disciple-of-ferianth/ember-arts/flame-sight.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/blazing-speed.c");
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/fire-shield.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/blazing-speed.c",
        "/guilds/disciple-of-ferianth/ember-arts/kindle-spirit.c");
    addChild("/guilds/disciple-of-ferianth/ember-arts/fire-shield.c",
        "/guilds/disciple-of-ferianth/ember-arts/inner-fire.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/flame-blessing.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/flame-blessing.c",
        "/guilds/disciple-of-ferianth/ember-arts/kindle-spirit.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/burning-resolve.c");
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/heat-aura.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/burning-resolve.c",
        "/guilds/disciple-of-ferianth/ember-arts/blazing-speed.c");
    addChild("/guilds/disciple-of-ferianth/ember-arts/heat-aura.c",
        "/guilds/disciple-of-ferianth/ember-arts/fire-shield.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/ember-potency.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/ember-potency.c",
        "/guilds/disciple-of-ferianth/ember-arts/ember-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/fury-of-flames.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/fury-of-flames.c",
        "/guilds/disciple-of-ferianth/ember-arts/flame-blessing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/smoldering-presence.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/smoldering-presence.c",
        "/guilds/disciple-of-ferianth/ember-arts/heat-aura.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/fiery-determination.c");
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/ember-weapon.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/fiery-determination.c",
        "/guilds/disciple-of-ferianth/ember-arts/burning-resolve.c");
    addChild("/guilds/disciple-of-ferianth/ember-arts/ember-weapon.c",
        "/guilds/disciple-of-ferianth/ember-arts/fury-of-flames.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/enhanced-ember-potency.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/enhanced-ember-potency.c",
        "/guilds/disciple-of-ferianth/ember-arts/ember-potency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/sacred-flame-aura.c");
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/firebrand.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/sacred-flame-aura.c",
        "/guilds/disciple-of-ferianth/ember-arts/smoldering-presence.c");
    addChild("/guilds/disciple-of-ferianth/ember-arts/firebrand.c",
        "/guilds/disciple-of-ferianth/ember-arts/ember-weapon.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/indomitable-spirit.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/indomitable-spirit.c",
        "/guilds/disciple-of-ferianth/ember-arts/fiery-determination.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/divine-ember-potency.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/divine-ember-potency.c",
        "/guilds/disciple-of-ferianth/ember-arts/enhanced-ember-potency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/flame-tongue.c");
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/blazing-barrier.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/flame-tongue.c",
        "/guilds/disciple-of-ferianth/ember-arts/firebrand.c");
    addChild("/guilds/disciple-of-ferianth/ember-arts/blazing-barrier.c",
        "/guilds/disciple-of-ferianth/ember-arts/sacred-flame-aura.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/ferianths-vigor.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/ferianths-vigor.c",
        "/guilds/disciple-of-ferianth/ember-arts/indomitable-spirit.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/master-ember-potency.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/master-ember-potency.c",
        "/guilds/disciple-of-ferianth/ember-arts/divine-ember-potency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/soul-of-fire.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/soul-of-fire.c",
        "/guilds/disciple-of-ferianth/ember-arts/blazing-barrier.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/radiant-presence.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/radiant-presence.c",
        "/guilds/disciple-of-ferianth/ember-arts/soul-of-fire.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/supreme-ember-potency.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/supreme-ember-potency.c",
        "/guilds/disciple-of-ferianth/ember-arts/master-ember-potency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/ferianths-blessing.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/ferianths-blessing.c",
        "/guilds/disciple-of-ferianth/ember-arts/ferianths-vigor.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/mantle-of-flames.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/mantle-of-flames.c",
        "/guilds/disciple-of-ferianth/ember-arts/radiant-presence.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/avatar-of-ferianth.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/avatar-of-ferianth.c",
        "/guilds/disciple-of-ferianth/ember-arts/ferianths-blessing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyNinthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/divine-empowerment.c");

    addChild("/guilds/disciple-of-ferianth/ember-arts/divine-empowerment.c",
        "/guilds/disciple-of-ferianth/ember-arts/mantle-of-flames.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Ember Arts");
    Description("This research tree provides knowledge of utility and enhancement "
        "magic - the empowering aspect of Ferianth's sacred fire. Through study "
        "of ember arts, practitioners learn to enhance themselves and allies, "
        "providing buffs, protections, and magical augmentations through the "
        "divine warmth of the god of fire.");
    Source("disciple of ferianth");
    addResearchElement("/guilds/disciple-of-ferianth/ember-arts/ember-arts-root.c");
    TreeRoot("/guilds/disciple-of-ferianth/ember-arts/ember-arts-root.c");

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
    TwentyThirdLevel();
    TwentySeventhLevel();
    TwentyNinthLevel();
    ThirtyFirstLevel();
    ThirtyFifthLevel();
    ThirtySeventhLevel();
    ThirtyNinthLevel();
    FortyThirdLevel();
    FortyFifthLevel();
    FortySeventhLevel();
    FiftyFirstLevel();
    FiftyFifthLevel();
    FiftyNinthLevel();
}
