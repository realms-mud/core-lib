//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/monk/unarmed/measured-palm.c");
    addChild("/guilds/monk/unarmed/measured-palm.c",
        "/guilds/monk/unarmed/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/monk/unarmed/balanced-recovery.c");
    addChild("/guilds/monk/unarmed/balanced-recovery.c",
        "/guilds/monk/unarmed/measured-palm.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/monk/unarmed/open-hand-guard.c");
    addChild("/guilds/monk/unarmed/open-hand-guard.c",
        "/guilds/monk/unarmed/measured-palm.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/monk/unarmed/quiet-footwork.c");
    addChild("/guilds/monk/unarmed/quiet-footwork.c",
        "/guilds/monk/unarmed/measured-palm.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/monk/unarmed/joint-conditioning.c");
    addChild("/guilds/monk/unarmed/joint-conditioning.c",
        "/guilds/monk/unarmed/open-hand-guard.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("/guilds/monk/unarmed/hand-alignment.c");
    addChild("/guilds/monk/unarmed/hand-alignment.c",
        "/guilds/monk/unarmed/measured-palm.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/monk/unarmed/guarded-breath.c");
    addChild("/guilds/monk/unarmed/guarded-breath.c",
        "/guilds/monk/unarmed/quiet-footwork.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("/guilds/monk/unarmed/driving-elbow.c");
    addChild("/guilds/monk/unarmed/driving-elbow.c",
        "/guilds/monk/unarmed/hand-alignment.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/monk/unarmed/elbow-anatomy.c");
    addChild("/guilds/monk/unarmed/elbow-anatomy.c",
        "/guilds/monk/unarmed/driving-elbow.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("/guilds/monk/unarmed/crane-stance.c");
    addChild("/guilds/monk/unarmed/crane-stance.c",
        "/guilds/monk/unarmed/quiet-footwork.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{
    addResearchElement("/guilds/monk/unarmed/grounded-base.c");
    addChild("/guilds/monk/unarmed/grounded-base.c",
        "/guilds/monk/unarmed/joint-conditioning.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenthLevel()
{
    addResearchElement("/guilds/monk/unarmed/centering-breath.c");
    addChild("/guilds/monk/unarmed/centering-breath.c",
        "/guilds/monk/unarmed/guarded-breath.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("/guilds/monk/unarmed/disrupting-knee.c");
    addChild("/guilds/monk/unarmed/disrupting-knee.c",
        "/guilds/monk/unarmed/open-hand-guard.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighteenthLevel()
{
    addResearchElement("/guilds/monk/unarmed/knee-leverage.c");
    addChild("/guilds/monk/unarmed/knee-leverage.c",
        "/guilds/monk/unarmed/disrupting-knee.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("/guilds/monk/unarmed/centered-vitality.c");
    addChild("/guilds/monk/unarmed/centered-vitality.c",
        "/guilds/monk/unarmed/grounded-base.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySecondLevel()
{
    addResearchElement("/guilds/monk/unarmed/tiger-stance.c");
    addChild("/guilds/monk/unarmed/tiger-stance.c",
        "/guilds/monk/unarmed/driving-elbow.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFourthLevel()
{
    addResearchElement("/guilds/monk/unarmed/supple-form.c");
    addChild("/guilds/monk/unarmed/supple-form.c",
        "/guilds/monk/unarmed/quiet-footwork.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySixthLevel()
{
    addResearchElement("/guilds/monk/unarmed/rising-heel.c");
    addChild("/guilds/monk/unarmed/rising-heel.c",
        "/guilds/monk/unarmed/supple-form.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyEighthLevel()
{
    addResearchElement("/guilds/monk/unarmed/heel-trajectory.c");
    addChild("/guilds/monk/unarmed/heel-trajectory.c",
        "/guilds/monk/unarmed/rising-heel.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("/guilds/monk/unarmed/hammer-fist.c");
    addChild("/guilds/monk/unarmed/hammer-fist.c",
        "/guilds/monk/unarmed/grounded-base.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySecondLevel()
{
    addResearchElement("/guilds/monk/unarmed/fist-compression.c");
    addChild("/guilds/monk/unarmed/fist-compression.c",
        "/guilds/monk/unarmed/hammer-fist.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFourthLevel()
{
    addResearchElement("/guilds/monk/unarmed/patient-recovery.c");
    addChild("/guilds/monk/unarmed/patient-recovery.c",
        "/guilds/monk/unarmed/balanced-recovery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySixthLevel()
{
    addResearchElement("/guilds/monk/unarmed/restorative-breath.c");
    addChild("/guilds/monk/unarmed/restorative-breath.c",
        "/guilds/monk/unarmed/centering-breath.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyEighthLevel()
{
    addResearchElement("/guilds/monk/unarmed/sapping-palm.c");
    addChild("/guilds/monk/unarmed/sapping-palm.c",
        "/guilds/monk/unarmed/elbow-anatomy.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortiethLevel()
{
    addResearchElement("/guilds/monk/unarmed/meridian-lore.c");
    addChild("/guilds/monk/unarmed/meridian-lore.c",
        "/guilds/monk/unarmed/sapping-palm.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySecondLevel()
{
    addResearchElement("/guilds/monk/unarmed/stone-stance.c");
    addChild("/guilds/monk/unarmed/stone-stance.c",
        "/guilds/monk/unarmed/grounded-base.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFourthLevel()
{
    addResearchElement("/guilds/monk/unarmed/breath-economy.c");
    addChild("/guilds/monk/unarmed/breath-economy.c",
        "/guilds/monk/unarmed/restorative-breath.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySixthLevel()
{
    addResearchElement("/guilds/monk/unarmed/crushing-embrace.c");
    addChild("/guilds/monk/unarmed/crushing-embrace.c",
        "/guilds/monk/unarmed/disrupting-knee.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyEighthLevel()
{
    addResearchElement("/guilds/monk/unarmed/grappling-mechanics.c");
    addChild("/guilds/monk/unarmed/grappling-mechanics.c",
        "/guilds/monk/unarmed/crushing-embrace.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftiethLevel()
{
    addResearchElement("/guilds/monk/unarmed/meridian-strike.c");
    addChild("/guilds/monk/unarmed/meridian-strike.c",
        "/guilds/monk/unarmed/meridian-lore.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySecondLevel()
{
    addResearchElement("/guilds/monk/unarmed/vital-reading.c");
    addChild("/guilds/monk/unarmed/vital-reading.c",
        "/guilds/monk/unarmed/meridian-lore.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFourthLevel()
{
    addResearchElement("/guilds/monk/unarmed/flowing-stance.c");
    addChild("/guilds/monk/unarmed/flowing-stance.c",
        "/guilds/monk/unarmed/heel-trajectory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySixthLevel()
{
    addResearchElement("/guilds/monk/unarmed/iron-body.c");
    addChild("/guilds/monk/unarmed/iron-body.c",
        "/guilds/monk/unarmed/centered-vitality.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyEighthLevel()
{
    addResearchElement("/guilds/monk/unarmed/empty-hand.c");
    addChild("/guilds/monk/unarmed/empty-hand.c",
        "/guilds/monk/unarmed/fist-compression.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtiethLevel()
{
    addResearchElement("/guilds/monk/unarmed/empty-hand-theory.c");
    addChild("/guilds/monk/unarmed/empty-hand-theory.c",
        "/guilds/monk/unarmed/empty-hand.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySecondLevel()
{
    addResearchElement("/guilds/monk/unarmed/pulse-mapping.c");
    addChild("/guilds/monk/unarmed/pulse-mapping.c",
        "/guilds/monk/unarmed/meridian-strike.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFourthLevel()
{
    addResearchElement("/guilds/monk/unarmed/finishing-economy.c");
    addChild("/guilds/monk/unarmed/finishing-economy.c",
        "/guilds/monk/unarmed/empty-hand-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySixthLevel()
{
    addResearchElement("/guilds/monk/unarmed/returning-breath.c");
    addChild("/guilds/monk/unarmed/returning-breath.c",
        "/guilds/monk/unarmed/breath-economy.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyEighthLevel()
{
    addResearchElement("/guilds/monk/unarmed/returning-rhythm.c");
    addChild("/guilds/monk/unarmed/returning-rhythm.c",
        "/guilds/monk/unarmed/returning-breath.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventiethLevel()
{
    addResearchElement("/guilds/monk/unarmed/still-heart.c");
    addChild("/guilds/monk/unarmed/still-heart.c",
        "/guilds/monk/unarmed/pulse-mapping.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("unarmed discipline");
    Description("Deliberate unarmed forms, demonstrated combat practice, and "
        "balanced recovery.");
    Source("monk");
    deferResearchLoading();

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));

    addResearchElement("/guilds/monk/unarmed/root.c");
    TreeRoot("/guilds/monk/unarmed/root.c");

    FirstLevel();
    SecondLevel();
    ThirdLevel();
    FourthLevel();
    FifthLevel();
    SixthLevel();
    SeventhLevel();
    EighthLevel();
    NinthLevel();
    TenthLevel();
    TwelfthLevel();
    FourteenthLevel();
    SixteenthLevel();
    EighteenthLevel();
    TwentiethLevel();
    TwentySecondLevel();
    TwentyFourthLevel();
    TwentySixthLevel();
    TwentyEighthLevel();
    ThirtiethLevel();
    ThirtySecondLevel();
    ThirtyFourthLevel();
    ThirtySixthLevel();
    ThirtyEighthLevel();
    FortiethLevel();
    FortySecondLevel();
    FortyFourthLevel();
    FortySixthLevel();
    FortyEighthLevel();
    FiftiethLevel();
    FiftySecondLevel();
    FiftyFourthLevel();
    FiftySixthLevel();
    FiftyEighthLevel();
    SixtiethLevel();
    SixtySecondLevel();
    SixtyFourthLevel();
    SixtySixthLevel();
    SixtyEighthLevel();
    SeventiethLevel();
}
