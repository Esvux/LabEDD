var app = angular.module("UrbanEDD", []);
const base = 'http://localhost:8080/UrbanEDD/rest';

app.controller('ControladorTransbordos', function ControladorTransbordos($scope, $http, $log) {
  $scope.rutas = [
		{
			nombre: 'Ruta 1',
			codigo: 'R11'
		},
		{ 
			nombre: 'Ruta 2',
			codigo: 'R12'
		},
		{ 
			nombre: 'Ruta 3',
			codigo: 'R13'
		}
  	];

	$scope.registrarTransbordo = (codigo) => {
		$log.info("Transbordo en " + codigo);
		$http.post(
			base + '/estaciones', 
			{ nombre:codigo }
		).then(
			(data) => $log.info("Éxito"), 
			(error) => $log.error(error)
		);
	}

});