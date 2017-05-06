inherit "/lib/modules/combat/attacks/baseAttack.c";

public void init()
{
    ::init();
    setDamageType("physical");
    addHitDictionary(({
        "bite", "puncture", "lacerate", "slash" }));

    addSimileDictionary(({
        "slicing into ##TargetPossessive## ##BodyPart## soundly", "repeatedly in "
        "the ##BodyPart##", "with a ##BodyPart##-tearing force" }));
        
    addMissMessage("##AttackerName## ##Infinitive::snap## ##AttackerPossessive##"
        " fangs at the empty air.");
    
    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary## using ##AttackerPossessive## fangs.","1-50");
}




