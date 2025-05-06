import speech_recognition as sr
import sys
import os
import sounddevice as sd
import soundfile as sf
from unidecode import unidecode  # Pour normaliser le texte
from spellchecker import SpellChecker

def play_audio(file_path):
    """Joue un fichier audio avec sounddevice et soundfile."""
    try:
        if not os.path.exists(file_path):
            print(f"Erreur : Le fichier audio {file_path} n'existe pas.", flush=True)
            return

        data, samplerate = sf.read(file_path)
        sd.play(data, samplerate)
        sd.wait()
    except Exception as e:
        print(f"Erreur lors de la lecture audio : {e}", flush=True)

def reconnaitre_voix(prompt_type, retry=3):
    """Reconnaît la voix et applique des corrections."""
    try:
        audio_file = f"{prompt_type}.mp3"
        if os.path.exists(audio_file):
            play_audio(audio_file)
        else:
            print(f"Fichier audio {audio_file} non trouvé.", flush=True)
            return f"Erreur : Fichier audio {audio_file} non trouvé."

        recognizer = sr.Recognizer()
        with sr.Microphone() as source:
            recognizer.adjust_for_ambient_noise(source, duration=1)
            print("Parlez...", flush=True)
            audio = recognizer.listen(source, timeout=8, phrase_time_limit=8)

        texte = recognizer.recognize_google(audio, language="fr-FR")
        return nettoyer_texte(texte)

    except sr.WaitTimeoutError:
        return "Erreur : Aucun son détecté."
    except sr.UnknownValueError:
        if retry > 0:
            print("Aucune.voix.reconnue, nouvelle.tentative...", flush=True)
            return reconnaitre_voix(prompt_type, retry - 1)
        return "Erreur : Aucun son compris après plusieurs essais."
    except sr.RequestError as e:
        return f"Erreur : Service Google indisponible. Détails : {e}"
    except Exception as e:
        return f"Erreur système : {str(e)}"

def nettoyer_texte(texte):
    """Nettoie et corrige le texte reconnu."""
    texte = unidecode(texte)  # Supprime les accents et caractères spéciaux
    texte = texte.lower().strip()

    spell = SpellChecker(language="fr")
    mots = texte.split()
    texte_corrige = " ".join([spell.correction(mot) if mot in spell else mot for mot in mots])

    return texte_corrige.capitalize()

if __name__ == "__main__":
    if len(sys.argv) > 1:
        prompt_type = sys.argv[1]
        print(reconnaitre_voix(prompt_type), flush=True)
    else:
        print("Erreur : Type de prompt non spécifié.", flush=True)
