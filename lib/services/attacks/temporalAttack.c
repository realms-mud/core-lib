//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/services/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("temporal");
    damagesEthereal();
    addHitDictionary(({
        "age", "wither", "erode", "decay", "wilt", "sap", "deteriorate"
        }));

    addSimileDictionary(({
        "with a ripple through time", "with a wave of unnatural aging",
        "as years pass in an instant", "with a distortion of reality"
        }));

    addMissMessage("##AttackerName## ##Infinitive::gesture##, but the flow of time "
        "remains unchanged for ##TargetName##.");

    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary##.", "1-50");
    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName##, "
        "leaving them frail and aged.", "51-190");
}
