# Небольшой скрипт для проверки, имеется ли существо с заданным assetID в файлах Spore

import os

def findFile(path, assetID):
    files = os.listdir(path)
    for fileName in files:
        if not fileName.endswith('.pollen_metadata_t'):
            continue

        fullName = path + '\\' + fileName
        with open(fullName, encoding='utf-8') as f:
            for line in f:
                keyWords = line.split()
                if len(keyWords) >= 2 and keyWords[0] == 'assetID' and keyWords[1] == assetID:
                    return '"' + fullName + '"'
                
    return ''

assetID = '666'
print(findFile('D:\\Program Files\\SporeModder FX\\Projects\\Spore_Content\\creature_editorModel~', assetID))
print(findFile('D:\\Program Files\\SporeModder FX\\Projects\\Spore_EP1_Content_01\\creature_editorModel~', assetID))
print(findFile('D:\\Program Files\\SporeModder FX\\Projects\\Pollination\\creature_editorModel~', assetID))
