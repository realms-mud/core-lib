inherit "/lib/modules/combat/attacks/baseAttack.c";

public void init()
{
    ::init();
    setDamageType("sonic");
    addHitDictionary(({
        "blast", "slam", "flatten", "crush", "ram", "crash", "hammer" }));

    addSimileDictionary(({
        "with a wave of sonic energy", "with shrieking whips of sonic waves",
        "with a thunderous BOOM of sonic energy" }));
        
    addMissMessage("##AttackerName## ##Infinitive::cover## "
        "##AttackerPossessive## ears and ##Infinitive::scream##,"
        "'LA LA LA LA LA!'");
    
    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary##.", "1-50");
}



