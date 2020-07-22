#include "BFieldPlugin.h"

#include "Helpers/XmlHelper.h"

namespace gar {
    namespace gar_pandora {

        BFieldPlugin::BFieldPlugin(art::ServiceHandle<mag::MagneticField> &magFieldService) :
        fieldService(magFieldService)
        {
            /* nop */
        }

        //------------------------------------------------------------------------------------------------------------------------------------------

        float BFieldPlugin::GetBField(const pandora::CartesianVector &positionVector) const
        {
            G4ThreeVector PosVec(positionVector.GetX(), positionVector.GetY(), positionVector.GetZ());
            G4ThreeVector magfield = fieldService->FieldAtPoint(PosVec);
            return magfield[0];
        }

        //------------------------------------------------------------------------------------------------------------------------------------------

        pandora::StatusCode BFieldPlugin::Initialize()
        {
            /* nop */
            return pandora::STATUS_CODE_SUCCESS;
        }

        //------------------------------------------------------------------------------------------------------------------------------------------

        pandora::StatusCode BFieldPlugin::ReadSettings(const pandora::TiXmlHandle /*xmlHandle*/)
        {
            /* nop */
            return pandora::STATUS_CODE_SUCCESS;
        }
    }
}
