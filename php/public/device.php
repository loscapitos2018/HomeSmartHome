<?php
$prueba = "Prender Luz"
?>

<!doctype html>
<!--[if lt IE 7]>      <html class="no-js lt-ie9 lt-ie8 lt-ie7" lang=""> <![endif]-->
<!--[if IE 7]>         <html class="no-js lt-ie9 lt-ie8" lang=""> <![endif]-->
<!--[if IE 8]>         <html class="no-js lt-ie9" lang=""> <![endif]-->
<!--[if gt IE 8]><!--> <html class="no-js" lang=""> <!--<![endif]-->
    <head>
        <meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
        <title></title>
        <meta name="description" content="">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link rel="apple-touch-icon" href="apple-touch-icon.png">

        <link rel="stylesheet" href="css/font-awesome.min.css">
        <link rel="stylesheet" href="css/bootstrap.min.css">
        <style>
            body {
                padding-top: 50px;
                padding-bottom: 20px;
            }
        </style>
        <link rel="stylesheet" href="css/bootstrap-theme.min.css">
        <link rel="stylesheet" href="css/main.css">

        <script src="js/vendor/modernizr-2.8.3-respond-1.4.2.min.js"></script>
    </head>
    <body class="container">
        <!--[if lt IE 8]>
            <p class="browserupgrade">You are using an <strong>outdated</strong> browser. Please <a href="http://browsehappy.com/">upgrade your browser</a> to improve your experience.</p>
        <![endif]-->
<?php function prender() {
  alert ("accion");
}

?>



    <!-- Main jumbotron for a primary marketing message or call to action -->
    <div class="jumbotron">

         <h1>Home Smart Home</h1>
        <p>
           Controle su casa!
        </p>
        <p class="container">

          <form action="prenderled.php" method="post">

 <button id="b_verde" type="submit" class="btn btn-lg btn-success"><?php echo $prueba ?></button>
</form>
<form action="apagarled.php" method="post">
<br>
 <button id="b_rojo" type="submit" class="btn btn-lg btn-danger">Apagar luz</button>
</form>
          <!-- <div class="row">
          <div class="col-md-3 col-md-offset-3">
           <p> <button id="b_azul" type="button" class="btn btn-lg btn-primary">Azul</button>
           <p> <button id="b_verde" type="button" class="btn btn-lg btn-success">Verde</button>
           <p> <button id="b_rojo" type="button" class="btn btn-lg btn-danger">Rojo</button>
        </div>
          <div class="col-md-3">
            <p> <button id="b_stop" type="button" class="btn btn-lg btn-default">Blink</button>
            <p> <button id="b_off" type="button" class="btn btn-lg btn-default">Led OFF</button>
            <p> <button id="b_on" type="button" class="btn btn-lg btn-default" onclick="location='prenderled.php'">Led ON</button>
          </div>
        </div>

 -->


             

    </div>

      <hr>

      <footer>
       <p>&copy; FFLT 2018</p>
      </footer>
    </div> <!-- /container -->
    <script src="//ajax.googleapis.com/ajax/libs/jquery/1.11.2/jquery.min.js"></script>
    <script>window.jQuery || document.write('<script src="js/vendor/jquery-1.11.2.min.js"><\/script>')</script>

    <script src="js/vendor/bootstrap.min.js"></script>

    <script src="js/plugins.js"></script>
    <script src="js/main.js"></script>

    <!-- Google Analytics: change UA-XXXXX-X to be your site's ID. -->
    <script>
        (function(b,o,i,l,e,r){b.GoogleAnalyticsObject=l;b[l]||(b[l]=
        function(){(b[l].q=b[l].q||[]).push(arguments)});b[l].l=+new Date;
        e=o.createElement(i);r=o.getElementsByTagName(i)[0];
        e.src='//www.google-analytics.com/analytics.js';
        r.parentNode.insertBefore(e,r)}(window,document,'script','ga'));
        ga('create','UA-XXXXX-X','auto');ga('send','pageview');
    </script>
</body>
</html>
