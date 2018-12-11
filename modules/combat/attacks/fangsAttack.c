//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/combat/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        ::reset(arg);
        setDamageType("physical");
        addHitDictionary(({
            "bite", "puncture", "lacerate", "slash" }));

        addSimileDictionary(({
            "slicing into ##TargetPossessive## ##BodyPart## soundly", "repeatedly in "
            "the ##BodyPart##", "with a ##BodyPart##-tearing force" }));

        addMissMessage("##AttackerName## ##Infinitive::snap## ##AttackerPossessive##"
            " fangs at the empty air.");

        addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
            "##SimileDictionary## using ##AttackerPossessive## fangs.", "1-150");
    }
}




